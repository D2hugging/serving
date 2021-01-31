package(default_visibility = ["//visibility:public"])

cc_library(
    name = "servable_id",
    hdrs = ["servable_id.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "//util:hash",
    ],
)

cc_test(
    name = "servable_id_test",
    srcs = ["servable_id_test.cc"],
    deps = [
        ":servable_id",
        "@gtest//:gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "servable_data",
    hdrs = ["servable_data.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":servable_id",
    ],
)

cc_test(
    name = "servable_data_test",
    srcs = ["servable_data_test.cc"],
    deps = [
        ":servable_id",
        ":servable_data",
        "@gtest//:gtest",
        "@gtest//:gtest_main",
        "//util:status"
        
    ],
)