﻿#pragma once
#include "GRB.h"

#define GRB_ERROR_SERIES 600
#define NS(n) GRB::Rule::Chain::N(n)
#define TS(n) GRB::Rule::Chain::T(n)
#define ISNS(n)	GRB::Rule::Chain::isN(n)

namespace GRB
{
	Greibach greibach(NS('S'), TS('$'),				//стартовый символ, дно стека
		10,											//количество правил
		Rule(NS('S'), GRB_ERROR_SERIES + 0,			//Неверная структура программы
			5,		
			Rule::Chain(8, TS('i'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
			Rule::Chain(10, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), NS('S')),
			Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}')),
			Rule::Chain(9, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 1,			//Операторы программы
			16,		
			Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('r'), NS('E'), TS(';')),
			Rule::Chain(8, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';')),
			Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(4, TS('r'), NS('E'), TS(';'), NS('N')),
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(9, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(3, TS('p'), NS('E'), TS(';')),
			Rule::Chain(4, TS('p'), NS('E'), TS(';'), NS('N')),
			Rule::Chain(8, TS('w'), TS('('),NS('Z'), TS(')'), TS('{'), NS('K'), TS('}'), TS(';')),
			Rule::Chain(9, TS('w'), TS('('),NS('Z'), TS(')'), TS('{'), NS('K'), TS('}'), TS(';'), NS('N')),
			Rule::Chain(9, TS('c'), TS('('), TS('i'), TS(','), NS('P'), TS(','), NS('P'), TS(')'), TS(';')),
			Rule::Chain(10, TS('c'), TS('('), TS('i'), TS(','), NS('P'), TS(','), NS('P'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(7, TS('C'), TS('('), TS('i'), TS(','), NS('P'), TS(')'), TS(';')),
			Rule::Chain(8, TS('C'), TS('('), TS('i'), TS(','), NS('P'), TS(')'), TS(';'), NS('N'))
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 2,			//Выражение
			10,		
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('('), NS('E'), TS(','), NS('E'), TS(')')),
			Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')')),
			Rule::Chain(3, TS('i'), TS('('), TS(')')),
			Rule::Chain(2, TS('i'), NS('M')),
			Rule::Chain(2, TS('l'), NS('M')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(5, TS('i'), TS('('), NS('W'), TS(')'), NS('M'))
		),
		Rule(NS('W'), GRB_ERROR_SERIES + 3,			//Подвыражение
			4,		
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 4,			//Параметры функции
			2,		
			Rule::Chain(2, TS('t'), TS('i')),
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('F'))
		),
		Rule(NS('M'), GRB_ERROR_SERIES + 2,			//Выражение
			10,		
			Rule::Chain(2, TS('+'), NS('E')),
			Rule::Chain(2, TS('-'), NS('E')),
			Rule::Chain(2, TS('*'), NS('E')),
			Rule::Chain(2, TS('/'), NS('E')),
			Rule::Chain(2, TS('%'), NS('E')),
			Rule::Chain(3, TS('+'), NS('E'), NS('M')),
			Rule::Chain(3, TS('-'), NS('E'), NS('M')),
			Rule::Chain(3, TS('*'), NS('E'), NS('M')),
			Rule::Chain(3, TS('/'), NS('E'), NS('M')),
			Rule::Chain(3, TS('%'), NS('E'), NS('M'))
		),
		Rule(NS('Z'), GRB_ERROR_SERIES + 5,			//условие цикла
			8,
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS('<'), TS('l')),
			Rule::Chain(3, TS('i'), TS('>'), TS('l')),
			Rule::Chain(3, TS('l'), TS('<'), TS('i')),
			Rule::Chain(3, TS('l'), TS('>'), TS('i')), 
			Rule::Chain(3, TS('l'), TS('<'), TS('l')),
			Rule::Chain(3, TS('l'), TS('>'), TS('l'))
		),
		Rule(NS('K'), GRB_ERROR_SERIES + 6,			//тело цикла
			14,	
			Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(8, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';')),
			Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('K')),
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('K')),
			Rule::Chain(9, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('K')),
			Rule::Chain(3, TS('p'), NS('E'), TS(';')),
			Rule::Chain(4, TS('p'), NS('E'), TS(';'), NS('K')),
			Rule::Chain(8, TS('w'), TS('('), NS('Z'), TS(')'), TS('{'), NS('K'), TS('}'), TS(';')),
			Rule::Chain(9, TS('w'), TS('('), NS('Z'), TS(')'), TS('{'), NS('K'), TS('}'), TS(';'), NS('K')),
			Rule::Chain(9, TS('c'), TS('('), TS('i'), TS(','), NS('P'), TS(','), NS('P'), TS(')'), TS(';')),
			Rule::Chain(10, TS('c'), TS('('), TS('i'), TS(','), NS('P'), TS(','), NS('P'), TS(')'), TS(';'), NS('K')),
			Rule::Chain(7, TS('C'), TS('('), TS('i'), TS(','), NS('P'), TS(')'), TS(';')),
			Rule::Chain(8, TS('C'), TS('('), TS('i'), TS(','), NS('P'), TS(')'), TS(';'), NS('K'))
		),
		Rule(NS('P'), GRB_ERROR_SERIES + 7,			//id или литерал
			2,		
			Rule::Chain(1,TS('i')),
			Rule::Chain(1,TS('l'))
		)
	);
}
