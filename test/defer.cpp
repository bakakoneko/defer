#include <defer.hpp>

void defer_lambda();

void defer_function();

void defer_object();

void defer_no_macro();

int main() {
    defer_lambda();
    defer_function();
    defer_object();
    defer_no_macro();
}

void defer_lambda() {
    defer [] { puts("deferred lambda"); };
    puts("not deferred lambda");
}

void do_defer_function() {
    puts("deferred function");
}

void defer_function() {
    defer do_defer_function;
    puts("not deferred function");
}

struct object {
    void operator()() const noexcept {
        puts("deferred object");
    }
};

void defer_object() {
    defer object{};
    puts("not deferred object");
}

void defer_no_macro() {
    auto deferred = bkn::make_defer([]() { puts("deferred no macro"); });
    puts("not deferred no macro");
}
