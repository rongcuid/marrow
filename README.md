# Marrow (m-arrow)

## TODO

- [ ] Copy and not move children

## Naming Convention of public API

* Functions: `camelCase` with `marr` as prefix
* Identifiers: `camelCase`
* Pointers arguments: 
  * If nullable: prefix `z` (zero)
  * If taking ownership: prefix `m` (move)
    * Caller MUST ensure objects live long enough and MUST NOT use existing handles afterwards.
  * If must have unlimited lifetime: prefix `s` (static)
  * Otherwise, prefix `p` (pointer)
    * Any objects are copied locally, so they MUST only need to outlive the call
  * Pointer to pointers will have multiple prefixes in the same order as `*`
    * So `struct ArrowSchema **pmChildren` will move ownership of all the `struct ArrowSchema` objects, but not the array

## Calling Convention of public API

I follow [this](https://nullprogram.com/blog/2023/10/08/), mostly for the result type, with some extra restrictions: the `ok` field is a `bool`, and must always the first field. The actual values have the following cases:

* If result is a single value, value field is `value`.
* If result is an array, the fields are `items` and `len`.
* If result has multiple values, each value will be named descriptively