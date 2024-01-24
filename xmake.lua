add_rules("mode.debug", "mode.release")

target("marrow")
    add_includedirs("include", {public = true})
    set_kind("static")
    add_files("src/*.c")
