package(default_visibility = ["//visibility:public"])

cc_library(
    name = "servable_id",
    hdrs = ["servable_id.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "//util:hash",
        "@com_google_absl//absl/strings",
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

cc_library(
    name = "servable_handle",
    hdrs = ["servable_handle.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":loader",
        "//util:any_ptr",
        # "@org_tensorflow//tensorflow/core:lib",
    ],
)

cc_library(
    name = "source",
    hdrs = ["source.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":servable_data",
        # "@org_tensorflow//tensorflow/core:lib",
    ],
)

cc_library(
    name = "loader",
    hdrs = ["loader.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        ":source",
        # "//tensorflow_serving/resources:resources_cc_proto",
        "//util:any_ptr",
        # "@org_tensorflow//tensorflow/core:lib",
    ],
)