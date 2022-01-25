#ifndef DEFER_DEFER_HPP
#define DEFER_DEFER_HPP

#include <utility>

namespace bkn {
    template<typename F>
    struct deferred_function {
        constexpr explicit deferred_function(F&& f) : func_(std::forward<F>(f)) {}

        ~deferred_function() { func_(); }

    private:
        F func_;
    };

    constexpr inline struct make_defer_t {
        constexpr make_defer_t() = default;
        constexpr make_defer_t(const make_defer_t&) = delete;
        constexpr make_defer_t(make_defer_t&&) = delete;
        constexpr make_defer_t& operator=(const make_defer_t&) = delete;
        constexpr make_defer_t& operator=(make_defer_t&&) = delete;

        template<typename F>
        [[nodiscard]] constexpr deferred_function<F> operator=(F&& f) const noexcept {
            return deferred_function<F>{std::forward<F>(f)};
        }

        template<typename F>
        [[nodiscard]] constexpr deferred_function<F> operator()(F&& f) const noexcept {
            return deferred_function<F>{std::forward<F>(f)};
        }
    } make_defer;
}

#ifndef BKN_DEFER_DISABLE_KEYWORD
#define BKN_DEFER_DISABLE_KEYWORD 0
#endif

#define BKN_DEFER_CAT_2(a, b) a ## b
#define BKN_DEFER_MAKE_ID(x) BKN_DEFER_CAT_2(__defer_, x)
#define BKN_DEFER_BEGIN_DEFER_STMT auto BKN_DEFER_MAKE_ID(__LINE__) = ::bkn::make_defer =

#if !BKN_DEFER_DISABLE_KEYWORD
#define defer BKN_DEFER_BEGIN_DEFER_STMT
#endif

#endif //DEFER_DEFER_HPP
