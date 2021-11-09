#include "Absyn.h"
#include "Semant.h"

using namespace absyn;

Symbol	arg,
		arg2,
		Bool,
		concat,
		cool_abort,
		copy_,
		Int,
		in_int,
		in_string,
		IO,
		isProto,
		length,
		Main,
		main_meth,
		No_class,
		No_type,
		Object,
		out_int,
		out_string,
		prim_slot,
		self,
		SELF_TYPE,
		Str,
		str_field,
		substr,
		type_name,
		val;

void initialize_constants(void)
{
	arg = idtable.add_string("arg");
	arg2 = idtable.add_string("arg2");
	Bool = idtable.add_string("Bool");
	concat = idtable.add_string("concat");
	cool_abort = idtable.add_string("abort");
	copy_ = idtable.add_string("copy");
	Int = idtable.add_string("Int");
	in_int = idtable.add_string("in_int");
	in_string = idtable.add_string("in_string");
	IO = idtable.add_string("IO");
	isProto = idtable.add_string("isProto");
	length = idtable.add_string("length");
	Main = idtable.add_string("Main");
	main_meth = idtable.add_string("main");
	//   _no_class is a symbol that can't be the name of any
	//   user-defined class.
	No_class = idtable.add_string("_no_class");
	No_type = idtable.add_string("_no_type");
	Object = idtable.add_string("Object");
	out_int = idtable.add_string("out_int");
	out_string = idtable.add_string("out_string");
	prim_slot = idtable.add_string("_prim_slot");
	self = idtable.add_string("self");
	SELF_TYPE = idtable.add_string("SELF_TYPE");
	Str = idtable.add_string("String");
	str_field = idtable.add_string("_str_field");
	substr = idtable.add_string("substr");
	type_name = idtable.add_string("type_name");
	val = idtable.add_string("_val");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Type Checking Features
//
//  For each class of expression, there is a tc method to typecheck it.
//  The tc methods make use of the environments previously constructred
//  for each class.  
//  Please implement the following type checking method.
//
//  YOU ARE NOT ALLOWED TO CALL tc_teacher VERSION
///////////////////////////////////////////////////////////////////////////////

void Attr::tc_student(EnvironmentP env)
{
	//your implementation here
	//variable_name : TypeName <- init_exp
	//errors should be detected:
	//  TypeName doesn't exist
	//  If init_exp is provided, the type of init_exp is not compatible with TypeName
}


Symbol IntExp::tc_student(EnvironmentP)
{
	type = Int;
	return Int;
}

Symbol BoolExp::tc_student(EnvironmentP)
{
	type = Bool;
	return Bool;
}

Symbol StringExp::tc_student(EnvironmentP)
{
	type = Str;
	return Str;
}

Symbol OpExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//for operators other than EQ: both operands must be Int
	//for EQ operators, either operands canNOT be Int, Str, Bool.

	return type;
}


Symbol NotExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//NOT expr
	//The type of expr must be Bool

	return type;
}

Symbol ObjectExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//The variable name doesn't exist in the variable symbol table

	return type;
}

Symbol NewExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//Class name is undefined.

	return type;
}

Symbol IsvoidExp::tc_student(EnvironmentP env)
{
	//your implementation here

	return type;
}

Symbol LetExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//let variableName : TypeName <- init_expr let_exp
	//Typename doesn't exist
	//Type of init_expr is not compatible with TypeName
	//variableName cannot be 'self'
	//Don't forget to enter variable scope before adding variable to symbol table and exit variable scope
	//after processing let_exp
	return type;
}

Symbol BlockExp::tc_student(EnvironmentP env)
{
	//your implementation here
	return type;
}


Symbol AssignExp::tc_student(EnvironmentP env)
{
	//your implementation here
	//variableName <- expr

	//variable name cannot be 'self'
	//variableName undefined
	//Type of expr is not compatible with the type of variableName

	return type;
}

Symbol CallExp::tc_student(EnvironmentP env)
{
	//No need to implement this method
	return No_type;
}

Symbol StaticCallExp::tc_student(EnvironmentP env)
{
	//No need to implement this method
	return No_type;
}


Symbol IfExp::tc_student(EnvironmentP env)
{
	//your implementation here

	//predicate is not Bool

	return type;
}

Symbol WhileExp::tc_student(EnvironmentP env)
{
	//your implementation here

	//predicate is not Bool

	return Object;
}

Symbol Branch_class::tc_student(EnvironmentP env)
{
	//No need to implement
	return expr->tc(env);
}

Symbol CaseExp::tc_student(EnvironmentP env)
{
	//No need to implement this
	return No_type;
}

void Method::tc_student(EnvironmentP env)
{
	//No need to implement this
}

void Formal_class::tc_student(EnvironmentP env)
{
	//No need to implement this
}

Symbol NoExp::tc_student(EnvironmentP)
{
	type = No_type;
	return No_type;
}