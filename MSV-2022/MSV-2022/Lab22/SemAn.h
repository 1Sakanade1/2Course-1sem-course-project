#pragma once
#include "Log.h"
#include "LexAnalysis.h"
#include "IT.h"

namespace Semantic
{
	bool semanticsCheck(LT::LexTable& lexTable, Log::LOG& log, IT::IdTable& idTable);
};