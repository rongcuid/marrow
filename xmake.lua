add_rules("mode.debug", "mode.release")

set_languages("c17")

target("marrow")
    add_includedirs("include", {public = true})
    add_includedirs("src/marrow")
    set_kind("static")
    add_files("src/**/*.c")
