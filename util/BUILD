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