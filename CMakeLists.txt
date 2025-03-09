cmake_minimum_required(VERSION 3.14)
project(config_loader)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/config-loader)
include_directories(include/config-loader/core)
include_directories(include/config-loader/deserialize)
include_directories(include/config-loader/parsers)
include_directories(include/config-loader/serialize)
include_directories(include/config-loader/utils)
include_directories(test/ut)

add_executable(config_loader
        include/config-loader/core/DefineSchema.h
        include/config-loader/core/ForEachField.h
        include/config-loader/core/ReflectedTraits.h
        include/config-loader/deserialize/CompoundDeserializeTraits.h
        include/config-loader/deserialize/Deserializer.h
        include/config-loader/deserialize/DeserializeTraits.h
        include/config-loader/deserialize/DeserializeTraitsDecl.h
        include/config-loader/deserialize/PrimitiveDeserializeTraits.h
        include/config-loader/parsers/JsonCppParser.h
        include/config-loader/parsers/TinyXML2Parser.h
        include/config-loader/parsers/UnsupportedParser.h
        include/config-loader/parsers/YamlCppParser.h
        include/config-loader/serialize/CompoundSerializeTraits.h
        include/config-loader/serialize/PrimitiveSerializeTraits.h
        include/config-loader/serialize/Serializer.h
        include/config-loader/serialize/SerializeTraits.h
        include/config-loader/serialize/SerializeTraitsDecl.h
        include/config-loader/serialize/TypeSerializer.h
        include/config-loader/utils/Assertion.h
        include/config-loader/utils/CommonTraits.h
        include/config-loader/utils/ConstexprStringUtils.h
        include/config-loader/utils/Log.h
        include/config-loader/utils/RepeatMacro.h
        include/config-loader/ConfigLoader.h
        include/config-loader/ConfigLoaderNS.h
        include/config-loader/Result.h
        src/utils/GetFileContent.cpp
        test/ut/ConstexprStringTest.cpp
        test/ut/DeserializeConfig.h
        test/ut/DeserializerTest.cpp
        test/ut/JsonCppDeserializeTest.cpp
        test/ut/JsonCppTest.cpp
        test/ut/ReflectMacroTest.cpp
        test/ut/ResultChecking.cpp
        test/ut/SerializerTest.cpp
        test/ut/TinyXML2DeserializeTest.cpp
        test/ut/TinyXML2Test.cpp
        test/ut/TypeSerializerTest.cpp
        test/ut/UtilsTest.cpp
        test/ut/UTSchema.h
        test/ut/YamlCppDeserializeTest.cpp
        test/ut/YamlCppTest.cpp)
