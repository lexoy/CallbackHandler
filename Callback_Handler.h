/*******************************************************************
 *  Copyleft(c) 2015 under LGPL license
 *   
 *  FileName         : Callback_Handler.h
 *  BriefDescription : CallbackHandler is a template library 
                       which is regisiter and management Callbacks
                       whether it is C-Style(function-ptr) or
                       Cpp-Style(member-function-ptr).
 *  
 *  CreateDate  : 2015 / 10 /28
 *  Author      : lexo
 *  Mail        : lexo_y@icloud.com
 *  Description : New create this head file.
 *  
 *  ModifyDate  : N / A
 *  Author      : N / A
 *  Mail        : N / A
 *  Description : N / A
 ******************************************************************/

#pragma once

#include "def.h"

/*******************************************************************
*  C++ style callback implement
******************************************************************/
template <typename C, typename R, typename P>
callback_handler<C, R, P> :: callback_handler() : class_(NULL), function_(NULL) { }

template <typename C, typename R, typename P>
callback_handler<C, R, P> :: callback_handler(const C* class_, const function function_) : 
								  class_(const_cast<C*>(class_)), function_(function_) { }

template <typename C, typename R, typename P>
callback_handler<C, R, P> :: ~callback_handler() {
	class_    = NULL;
	function_ = NULL;
}

template <typename C, typename R, typename P>
void callback_handler<C, R, P> :: register_callback(const C* class_, const function function_) {
	this->class_ = const_cast<C*>(class_);
	this->function_ = function_;
}

template <typename C, typename R, typename P>
R callback_handler<C, R, P> :: operator()(const P& param) {
	return (class_->*function_)(param);
}


/*******************************************************************
*  C style callback implement
******************************************************************/
template <typename R, typename P>
callback_handler<NO_CLASS_TYPE, R, P> :: callback_handler() : function_(NULL) { }

template <typename R, typename P>
callback_handler<NO_CLASS_TYPE, R, P> :: callback_handler(const function function_) : function_(function_) { }

template <typename R, typename P>
callback_handler<NO_CLASS_TYPE, R, P> :: ~callback_handler() {
	function_ = NULL;
}

template <typename R, typename P>
void callback_handler<NO_CLASS_TYPE, R, P> :: register_callback(const function function_) {
	this->function_ = function_;
}

template <typename R, typename P>
R callback_handler<NO_CLASS_TYPE, R, P> :: operator()(const P& param) {
	return (*function_)(param);
}