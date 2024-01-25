add_rules("mode.debug", "mode.release")

target("marrow")
    add_includedirs("include", {public = true})
    add_includedirs("src")
    set_kind("static")
    add_files("src/*.c", "src/**/*.c")
