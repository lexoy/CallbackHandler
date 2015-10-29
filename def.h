/*******************************************************************
 *  Copyleft(c) 2015 under LGPL license
 *   
 *  FileName         : def.h
 *  BriefDescription : Common define to Callback_Handler.h.
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

#include <stdio.h>

typedef void NO_CLASS_TYPE;


template <typename C, typename R, typename P> class callback_handler {
protected:
	typedef R (C::*function)(P);

public:
	callback_handler(const C* class_, const function function_);
	callback_handler();
	~callback_handler();

public:
	void register_callback(const C* class_, const function function_);
	R operator()(const P& param);

private:
	C* class_;
	function function_;
};

template <typename R, typename P> class callback_handler <NO_CLASS_TYPE, R, P> {
protected:
	typedef R (*function)(P);

public:
	callback_handler(const function function_);
	callback_handler();
	~callback_handler();

public:
	void register_callback(const function function_);
	R operator()(const P& param);

private:
	function function_;
};