#pragma once

#include "stdafx.h"
#include "Generator.h"

namespace Gen
{

	bool CodeGeneration(LT::LexTable& lexTable, IT::IdTable& idTable)
	{
		std::ofstream result;          
		result.open("MSV-2022_RESULT.txt");
		bool printoccure = false;
		bool forcheck = false;
		bool isinequalityfound = false;

		result << "\'use strict\'\n";

		for (int i = 0; i < lexTable.size; i++)
		{

			switch (lexTable.table[i].lexema)
			{
			case LEX_STRING || LEX_INTEGER:
			{
			
			}
			case LEX_RETURN:
			{
				result << "return ";                        

				break;
			}
			case LEX_FUNCTION:
			{
				result << "function ";
				break;
			}

			case LEX_LEFTHESIS:
			{
				result << "(";
				break;
			}
			case LEX_RIGHTHESIS:
			{
				if (lexTable.table[i+1].lexema==LEX_LEFTBRACE)
				{
					if (forcheck) {
						result << "; i++";

						forcheck = false;
					}

					isinequalityfound == false;

				}

				result << ")";
				break;
			}
			case LEX_LEFTBRACE:
			{
				result << "\n{\n";
				break;
			}
			case LEX_RIGHTBRACE:
			{
				result << "}";
				if (lexTable.table[i+1].lexema != LEX_SEMICOLON)
					result << "\n";
				break;
			}
			case LEX_DECLARE:
			{
				result << "let ";
				break;
			}
			case LEX_EQUAL_SIGN:
			{
				result << " = ";
				break;
			}

			case LEX_SEMICOLON:
			{
				if (printoccure) {
					result << ")";
					printoccure = false;
				}


				result << ";\n";
				break;
			}
			case LEX_ID:
			{
				if (strcmp(idTable.table[lexTable.table[i].idxTI].id, "main") == 0)
					result << "function main()";
				else
				result << idTable.table[lexTable.table[i].idxTI].id;

				break;
			}
			case LEX_LITERAL:
			{
				switch(idTable.table[lexTable.table[i].idxTI].iddatatype){
					case 1:
					{
						result << idTable.table[lexTable.table[i].idxTI].value.vint;
						break;
					}
					case 2:
					{
						result << idTable.table[lexTable.table[i].idxTI].value.vstr.str;
						break;
					}
				}

				break;
			}
			case LEX_PRINT:
			{
				printoccure = true;
				result << "console.log(";
				break;
			}
			case PLUS:
			{
				result << "+";
				break;
			}
			case MINUS:
			{
				result << "-";
				break;
			}
			case STAR:
			{
				result << "*";
				break;
			}
			case DIRSLASH:
			{
				result << "/";
				break;
			}
			case PERCENT:
			{
				result << "%";
				break;
			}
			case LEX_ECHO:
			{

				


				for (int echocount = i; lexTable.table[echocount].lexema != ';'; echocount++) 
				{
					if (lexTable.table[echocount].lexema == MORE || lexTable.table[echocount].lexema == LESS) 
					{
						isinequalityfound = true;
					}

				}

				if(isinequalityfound)
				{
				result << "while";
				}
				else
				{
					forcheck = true;
					result << "for(let i = 0 ; i < ";
					i++;
				}
				break;
			}
			case LEX_COMMA:
			{
				result << ",";
				break;
			}
			case LEX_CONCATSTR:
			{
				i = i + 2;
				result << idTable.table[lexTable.table[i].idxTI].id<<'=';
				i = i + 2;
				if (lexTable.table[i].lexema == LEX_LITERAL)
					result << idTable.table[lexTable.table[i].idxTI].value.vstr.str << '+';
				else
					result << idTable.table[lexTable.table[i].idxTI].id << '+';
				i = i + 2;
				if (lexTable.table[i].lexema == LEX_LITERAL)
					result << idTable.table[lexTable.table[i].idxTI].value.vstr.str;
				else
					result << idTable.table[lexTable.table[i].idxTI].id;
				i++;
				break;
			}
			case LEX_COPYSTR:
			{
				i = i + 2;
				result << idTable.table[lexTable.table[i].idxTI].id << '=';
				i = i + 2;
				if (lexTable.table[i].lexema == LEX_LITERAL)
					result << idTable.table[lexTable.table[i].idxTI].value.vstr.str << '.';
				else
					result << idTable.table[lexTable.table[i].idxTI].id << '.';
				result << "slice()";
				i++;
				break;


			}
			}


		}

		result << "\nmain();";

		result.close();
		return true;

	}
}