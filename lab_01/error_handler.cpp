#include "error_handler.h"
#include "errors.h"


void process_error(int error)
{
	if (error == MEM_ERR)
		QMessageBox::warning(NULL, "Ошибка", "Ошибка выделения памяти!");
	else if (error == FILE_ERR)
		QMessageBox::warning(NULL, "Ошибка", "Ошибка открытия файла!");
	else if (error == READ_ERR)
		QMessageBox::warning(NULL, "Ошибка", "Ошибка чтения из файла!");
	else if (error == DATA_ERR)
		QMessageBox::warning(NULL, "Ошибка", "Ошибка чтения данных!");
	else if (error != OK)
		QMessageBox::warning(NULL, "Ошибка", "Неизвестная ошибка!");
}
