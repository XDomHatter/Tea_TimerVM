//
// Created by Administrator on 2023-07-25.
//

#ifndef $TEA_SRC_SHARE_RUNTIME_TEAEXCEPTION_HPP
#define $TEA_SRC_SHARE_RUNTIME_TEAEXCEPTION_HPP

#include <oop/Constant.hpp>
#include <list>

class TExceptionHandler {
public:
    CLASS_Constant *exception_klass;
    u2 start_pc;
    u2 end_pc;
    u2 handle_pc;

    TExceptionHandler(CLASS_Constant *k, u2 start_pc, u2 end_pc, u2 handle_pc)
        : exception_klass(k), start_pc(start_pc), end_pc(end_pc), handle_pc(handle_pc) {}

    inline bool can_handle(CLASS_Constant *e, u2 pc) const {
        return exception_klass->equal(e) &&
            start_pc <= pc &&
            end_pc   >= pc;
    }
};

class TExceptionHandlerSet {
    int handler_count;
    std::list<TExceptionHandler *> *handlers;
public:
    ///
    TExceptionHandlerSet(int handler_count, std::list<TExceptionHandler *> *handlers)
        : handler_count(handler_count), handlers(handlers) {}
    ~TExceptionHandlerSet() {
        Memory::free_mem(handlers);
    }

    /// Check the handlers list
    /// @param e Exception class to handle
    /// @return pc of handling code
    inline int handle_exception(CLASS_Constant *e, u2 pc) {
        for(TExceptionHandler *handler : *handlers) {
            if(handler->can_handle(e, pc)) {
                return handler->handle_pc;
            }
        }
    }
};

#endif //$TEA_SRC_SHARE_RUNTIME_TEAEXCEPTION_HPP
