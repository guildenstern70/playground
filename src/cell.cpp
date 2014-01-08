/*
*
* 	CELL.CPP
*	Cell class
*
*	(C) Alessio Saltarin 2014
*
*/
#include "cell.h"

#include <string>
#include <sstream>

const char* Cell::tostring() const
{
	ostringstream cell_representation;

	cell_representation << "[";
	cell_representation.width(2);
	cell_representation << _x << ",";
	cell_representation.width(2);
	cell_representation	<< _y
						<< "]: ("
						<< _color
						<< ","
						<< _value
						<< ")"
						<< ends;

	return cell_representation.str().c_str();
}
