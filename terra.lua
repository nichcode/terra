
project "terra"
    language "C++"
    kind "StaticLib"

    targetdir(target_dir)
    objdir(obj_dir)

    if (_OPTIONS["build_test"]) then
        files {
            "terra.lua"
        }
    end    

    files {
        "include/**.h",
        "src/**.cpp",
        "src/**.h",
    }

    includedirs {
        "include",
        "src",
        "%{wks.location}/vendor/prime/include"
    }

    links {
        "prime"
    }