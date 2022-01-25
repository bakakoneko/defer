# Defer

A C++ library for deferring the execution of a function until the end of a scope.

## Usage

Refer to the [test file](test/defer.cpp) until I write examples.

## Configuration

If you don't want the `defer` keyword macro to be defined, you can set `BKN_DEFER_DISABLE_KEYWORD` before including the
header file to disable it. If you would like to make your own keyword macro, you can use the
`BKN_DEFER_BEGIN_DEFER_STMT` macro. Generally, `BKN_DEFER_BEGIN_DEFER_STMT` should not be used directly as it was
designed to avoid name conflicts. An example of a custom keyword macro is shown below.

```cpp
#define my_defer BKN_DEFER_BEGIN_DEFER_STMT
```

Alternatively, if you would like to avoid keyword macros entirely, then you can call `bkn::make_defer` directly.

```cpp
// Any name will work as long as it is unique.
auto deferred_func = bkn::make_defer([] {
// do something
});
```

## License

This project is licensed under the BSL-1.0 license. View [LICENSE](LICENSE) for details.
