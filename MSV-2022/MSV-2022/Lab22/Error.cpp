#include "stdafx.h"
#include "Error.h"

namespace Error
{
	//    0 - 99 - системные ошибки
	 // 100 - 109 - ошибки параметров
	 // 110 - 119 - ошибки открытия и чтения файлов

	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,	"Недопустимый код ошибки"),
		ERROR_ENTRY(1,	"Системный сбой"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),

		ERROR_ENTRY(100,	"Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,	"Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),

		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY(113, "Ошибка при создании файла выхода (-out)"),
		ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115), ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117),
		ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120, "Таблица лексем: превышен допустимый размер таблицы"),
		ERROR_ENTRY(121, "Превышена длина имя переменной или недопустимое имя переменной"),
		ERROR_ENTRY(122, "Таблица идентификаторов: превышен допустимый размер таблицы"),
		ERROR_ENTRY(123, "[LEX]#: нераспознанная лексема"),
		ERROR_ENTRY(124, "[LEX]#: нарушен формат строкового литерала"),
		ERROR_ENTRY(125, "[LEX]#: перезапись идентификатора"),
		ERROR_ENTRY(126, "[LEX]#: неизвестная переменная"),
		ERROR_ENTRY(127, "[LEX]#: превышена длина строкового литерала"),
		ERROR_ENTRY(128, "Не удалось создать файл с таблицами лексем и идентификаторов"),
		ERROR_ENTRY(129, "[LEX]#: найдено несколько точек входа (main)"),
		ERROR_ENTRY(130, "[LEX]#Лексический анализ: отсутствие ключевого слова declare при объявлении переменной"),
		ERROR_ENTRY_NODEF(131),ERROR_ENTRY_NODEF(132),ERROR_ENTRY_NODEF(133),ERROR_ENTRY_NODEF(134),ERROR_ENTRY_NODEF(135),
		ERROR_ENTRY_NODEF(136),ERROR_ENTRY_NODEF(137),ERROR_ENTRY_NODEF(138),ERROR_ENTRY_NODEF(139),
		ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160),ERROR_ENTRY_NODEF10(170),
		ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200),

		ERROR_ENTRY(300, "[SEM]# Необъявленный идентификатор"),
		ERROR_ENTRY(301, ""),
		ERROR_ENTRY(302, ""),
		ERROR_ENTRY(303, "[SEM]# В объявлении не указан тип идентификатора"),
		ERROR_ENTRY(304, ""),
		ERROR_ENTRY(305, ""),
		ERROR_ENTRY(306, "[SEM]# Попытка вернуть значение в процедуре"),
		ERROR_ENTRY(307, ""),
		ERROR_ENTRY(308, "[SEM]# Кол-во ожидаемыех функцией и передаваемых параметров не совпадают"),//est'
		ERROR_ENTRY(309, "[SEM]# Несовпадение типов передаваемых параметров"),//est'
		ERROR_ENTRY(310, "[SEM]# Попытка присвоить значение переменной типа vacuum"),
		ERROR_ENTRY(311, "[SEM]# Обнаружен символ \'. Возможно, не закрыт строковый литерал"),//это проверит лексический
		ERROR_ENTRY(312, "[SEM]# Превышен размер строкового литерала"),
		ERROR_ENTRY(313, "[SEM]# Недопустимый целочисленный литерал"),
		ERROR_ENTRY(314, "[SEM]# Типы данных в выражении не совпадают"),//есть
		ERROR_ENTRY(315, "[SEM]# Тип функции и возвращаемого значения не совпадают"),//есть
		ERROR_ENTRY(316, "[SEM]# Попытка вернуть значениее другого типа"),
		ERROR_ENTRY(317, "[SEM]# Неверное условное выражение"),//есть условия только больше и меньше
		ERROR_ENTRY(318, "[SEM]# Деление на ноль"),//есть
		ERROR_ENTRY(319, ""),
		ERROR_ENTRY(320,"[SEM]# Попытка произвести арифметическую операцию со строкой"),//есть
		ERROR_ENTRY(321,"[SEM]# Неверно указаны параметры для concatstr"),//есть
		ERROR_ENTRY(322,"[SEM]# Неверно указаны параметры для copystr"),//есть
		
		
	    ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),	
		ERROR_ENTRY(600,"Неверная структура программы"),
		ERROR_ENTRY(601,"Ошибочный оператор"),
		ERROR_ENTRY(602,"Ошибка в выражении"),
		ERROR_ENTRY(603,"Ошибка при указании подвыражения"),
		ERROR_ENTRY(604,"Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY(605,"Ошибка в условии цикла"),
		ERROR_ENTRY(606,"Ошибка в выражении в цикле"),
		ERROR_ENTRY(607,"Ошибка. ожидался идентификатор или литерал"),
		ERROR_ENTRY_NODEF(608),
		ERROR_ENTRY_NODEF(609),
		ERROR_ENTRY_NODEF10(610),ERROR_ENTRY_NODEF10(620),ERROR_ENTRY_NODEF10(630),ERROR_ENTRY_NODEF10(640),
		ERROR_ENTRY_NODEF10(650),ERROR_ENTRY_NODEF10(660),ERROR_ENTRY_NODEF10(670),ERROR_ENTRY_NODEF10(680),
		ERROR_ENTRY_NODEF10(690),

		ERROR_ENTRY_NODEF100(700),
		ERROR_ENTRY_NODEF100(800),
		ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id)
	{
		if (id > ERROR_MAX_ENTRY - 1 || id < 1)
			return errors[0];
		else
			return errors[id];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > ERROR_MAX_ENTRY - 1 || id < 1)
			return errors[0];
		else
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
	}
};