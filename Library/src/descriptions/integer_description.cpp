#include <pydbc/descriptions/integer_description.h>

#include <sqlext.h>

#include <boost/variant/get.hpp>
#include <cstring>

namespace pydbc {

integer_description::integer_description() = default;
integer_description::~integer_description() = default;

std::size_t integer_description::do_element_size() const
{
	return sizeof(long);
}

SQLSMALLINT integer_description::do_column_c_type() const
{
	return SQL_C_SBIGINT;
}

SQLSMALLINT integer_description::do_column_sql_type() const
{
	return SQL_BIGINT;
}

field integer_description::do_make_field(char const * data_pointer) const
{
	return {*reinterpret_cast<long const *>(data_pointer)};
}

void integer_description::do_set_field(cpp_odbc::writable_buffer_element & element, field const & value) const
{
	auto const as_long = boost::get<long>(value);
	memcpy(element.data_pointer, &as_long, element_size());
	element.indicator = element_size();
}

}
