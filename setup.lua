
target_dir = "%{wks.location}/bin/"
obj_dir = "%{wks.location}/bin-int"

newoption {
    trigger = "build_test",
    description = "build terra tests"
}

workspace "terra"
    if (_OPTIONS["build_test"]) then
        startproject "terra-test"
    end

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

    externalwarnings "off"

    filter {"system:windows", "configurations:*"}
        architecture "x64"
        systemversion "latest"
        cppdialect "C++20"
        staticruntime "off"

    filter "configurations:Debug"
        symbols "on"
        runtime "Debug"

        defines {
            "PCONFIG_DEBUG"
        }

    filter "configurations:Release"
        symbols "off"
        runtime "Release"
        optimize "full"
        

    include "terra.lua"

    -- vendor
    include "vendor/prime/prime.lua"
        
    -- prime-test
    if (_OPTIONS["build_test"]) then
        include "test/test.lua"
    end
