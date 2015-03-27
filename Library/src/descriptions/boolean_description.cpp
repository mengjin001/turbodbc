#include <pydbc/descriptions/boolean_description.h>

#include <sqlext.h>

namespace pydbc {

boolean_description::boolean_description() = default;
boolean_description::~boolean_description() = default;

std::size_t boolean_description::do_element_size() const
{
	return sizeof(char);
}

SQLSMALLINT boolean_description::do_column_c_type() const
{
	return SQL_C_BIT;
}

SQLSMALLINT boolean_description::do_column_sql_type() const
{
	return SQL_BIT;
}

field boolean_description::do_make_field(char const * data_pointer) const
{
	return {static_cast<bool>(*data_pointer)};
}

void boolean_description::do_set_field(cpp_odbc::writable_buffer_element & element, field const & value) const
{
	throw 42;
}

}
