package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hash",
    srcs = ["hash.cc"],
    hdrs = ["hash.h"],
    visibility = [
        "//visibility:public",
    ],
)


cc_library(
    name = "status",
    srcs = ["status.cc"],
    hdrs = ["status.h", "slice.h"],
    visibility = [
        "//visibility:public",
    ],
)

cc_library(
    name = "stringpiece",
    hdrs = ["stringpiece.h"],
    deps = [
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "any_ptr",
    hdrs = ["any_ptr.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "micros",
    hdrs = ["micros.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "threadpool",
    hdrs = ["threadpool.h"],
    deps = [
        ":micros",
        "@com_google_absl//absl/synchronization"
    ],
    visibility = ["//visibility:public"],
)


cc_library(
    name = "threadpool_test",
    srcs = ["threadpool_test.cc"],
    deps = [
        ":threadpool",
        "@com_google_absl//absl/synchronization",
        "@gtest//:gtest",
        "@gtest//:gtest_main",
    ]
)