#include "SemAn.h"
#include"Error.h"
#include"IT.h"
#include"LT.h"
#include"LexAnalysis.h"


namespace Semantic																																																												//проверяет на два мейна, параметры функции, правильное присвоение переменным
{
	bool Semantic::semanticsCheck(LT::LexTable& lexTable, Log::LOG& log ,IT::IdTable& idTable)
	{
		bool sem_ok = true;

		bool isret = false;


		for (int i = 0; i < lexTable.size; i++)
		{
			switch (lexTable.table[i].lexema)
			{
			case LEX_DECLARE:
			{
				if (lexTable.table[i + 1].lexema != 't')
				{
					sem_ok = false;
					throw ERROR_THROW_IN(303, lexTable.table[i].sn, -1);
					break;
				}

				break;
			}
			case LEX_ID:
			{

				if (lexTable.table[i - 1].lexema == LEX_FUNCTION)
				{
					
					IT::IDDATATYPE ftype = idTable.table[lexTable.table[i].idxTI].iddatatype;
					int j = i + 1;
					bool procedurefail = true;
					while (lexTable.table[j].lexema != LEX_RETURN ){
						j++;
						if (ftype == IT::VAC && lexTable.table[j].lexema == LEX_FUNCTION) {
							procedurefail = false;
						}
						if (ftype == IT::VAC && lexTable.table[j].lexema == LEX_ID && lexTable.table[j + 1].lexema == LEX_LEFTBRACE) {
							procedurefail = false;
						}
						if (ftype == IT::INT && lexTable.table[j].lexema == LEX_FUNCTION) {
							throw ERROR_THROW_IN(315, lexTable.table[i].sn, -1);
						}
						if (ftype == IT::INT && lexTable.table[j].lexema == LEX_ID && lexTable.table[j+1].lexema == LEX_LEFTBRACE) {
							throw ERROR_THROW_IN(315, lexTable.table[i].sn, -1);
						}
					}
					if (ftype == IT::VAC&&procedurefail) {
						throw ERROR_THROW_IN(315, lexTable.table[i].sn, -1);
					}

					if (ftype == IT::STR || ftype == IT::INT) {
						
						if (ftype != idTable.table[lexTable.table[j + 1].idxTI].iddatatype)
						{
							sem_ok = false;
							throw ERROR_THROW_IN(315, lexTable.table[i].sn, -1);
						}
					}
					break;
				}
				if (lexTable.table[i + 1].lexema == LEX_LEFTHESIS && lexTable.table[i - 1].lexema != LEX_FUNCTION)
				{
					int parms = 0;
					for (int j = i + 1; lexTable.table[j].lexema != LEX_RIGHTHESIS; j++)
					{	
						if (lexTable.table[j].lexema == LEX_ID || lexTable.table[j].lexema == LEX_LITERAL)
						{
							parms++;
							IT::IDDATATYPE ctype = idTable.table[lexTable.table[j].idxTI].iddatatype;
							if (ctype != idTable.table[lexTable.table[i].idxTI].parmtype[parms - 1])
							{
								sem_ok = false;
								throw ERROR_THROW_IN(309, lexTable.table[i].sn, -1);
								break;
							}
						}
					}
					if (parms != idTable.table[lexTable.table[i].idxTI].parmQuantity)
					{
						sem_ok = false;
						throw ERROR_THROW_IN(308, lexTable.table[i].sn, -1);
						break;
					}
				}
				break;
			}

			case LEX_EQUAL_SIGN:
			{

				bool skip = false;
				IT::IDDATATYPE mtype = idTable.table[lexTable.table[i - 1].idxTI].iddatatype;
				for (int j = i; lexTable.table[j].lexema != LEX_SEMICOLON; j++)
				{
					if (lexTable.table[j].lexema == LEX_LEFTHESIS)
						while (lexTable.table[j].lexema != LEX_RIGHTHESIS)
						{
							j++;
						}
					if ((lexTable.table[j].lexema == LEX_ID || lexTable.table[j].lexema == LEX_LITERAL))
					{
						if (mtype == IT::VAC) {
							throw ERROR_THROW_IN(310, lexTable.table[i].sn, -1);
						}

						if (mtype != idTable.table[lexTable.table[j].idxTI].iddatatype)
						{
							sem_ok = false;
							throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
						}
					}
				}
				break;
			}
			case LEX_DIRSLASH:
			{
				IT::IDDATATYPE type = idTable.table[lexTable.table[i + 1].idxTI].iddatatype;

				if (type == IT::INT) {
					int value = idTable.table[lexTable.table[i + 1].idxTI].value.vint;
					if (value == 0) {
						sem_ok = false;
						throw ERROR_THROW_IN(318, lexTable.table[i].sn, -1);
						break;
					}
				}
				

				if (lexTable.table[i - 1].lexema == 'i')
				{

					IT::IDDATATYPE ftype = idTable.table[lexTable.table[i - 1].idxTI].iddatatype;
					if (ftype == IT::STR) {

						sem_ok = false;
						throw ERROR_THROW_IN(320, lexTable.table[i].sn, -1);
						break;
					}
				}

				if (lexTable.table[i + 1].lexema == 'i')
				{

					IT::IDDATATYPE ftype = idTable.table[lexTable.table[i + 1].idxTI].iddatatype;

					if (ftype == IT::STR) {

						sem_ok = false;
						throw ERROR_THROW_IN(320, lexTable.table[i].sn, -1);
						break;
					}
					
				}
				break;
			}
			case PLUS: case MINUS: case STAR: case PERCENT: case LESS: case MORE:
			{
				if (lexTable.table[i - 1].lexema == 'i')
				{

					IT::IDDATATYPE ftype = idTable.table[lexTable.table[i - 1].idxTI].iddatatype;
					if (ftype == IT::STR) {

						sem_ok = false;
						throw ERROR_THROW_IN(320, lexTable.table[i].sn, -1);
						break;
					}
				}

				if ( lexTable.table[i + 1].lexema == 'i')
				{

					IT::IDDATATYPE ftype = idTable.table[lexTable.table[i + 1].idxTI].iddatatype;

					if(ftype == IT::STR){

					sem_ok = false;
					throw ERROR_THROW_IN(320, lexTable.table[i].sn, -1);
					break;
					}
				}


				break;
			}
			case LEX_CONCATSTR:
			{


				IT::IDDATATYPE IDtype = idTable.table[lexTable.table[i + 2].idxTI].iddatatype;

				if (IDtype != IT::STR)
				{
					sem_ok = false;
					throw ERROR_THROW_IN(321, lexTable.table[i].sn, -1);
					break;
				}

				IDtype = idTable.table[lexTable.table[i + 4].idxTI].iddatatype;

				if (IDtype != IT::STR)
				{
					sem_ok = false;
					throw ERROR_THROW_IN(321, lexTable.table[i].sn, -1);
					break;
				}
				IDtype = idTable.table[lexTable.table[i + 6].idxTI].iddatatype;

				if (IDtype != IT::STR)
				{
					sem_ok = false;
					throw ERROR_THROW_IN(321, lexTable.table[i].sn, -1);
					break;
				}
			
				break;
			}

			case LEX_COPYSTR:
			{

				IT::IDDATATYPE IDtype = idTable.table[lexTable.table[i + 2].idxTI].iddatatype;

				if (IDtype != IT::STR)
				{
					sem_ok = false;
					throw ERROR_THROW_IN(322, lexTable.table[i].sn, -1);
					break;
				}

				IDtype = idTable.table[lexTable.table[i + 4].idxTI].iddatatype;

				if (IDtype != IT::STR)
				{
					sem_ok = false;
					throw ERROR_THROW_IN(322, lexTable.table[i].sn, -1);
					break;
				}

				break;
			}
			}
		}

		return sem_ok;
		}
	
};
