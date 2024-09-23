#ifndef RWSTRING_HPP_INCLUDED
#define RWSTRING_HPP_INCLUDED

/* Funciones auxiliares para serializar struct que contengan strings
 * Incluir en main luego de using namespace std; y de definir bufsize
 */

void writestring(fstream &fs, string str, int largo)
{
	str.resize(largo);
	fs.write(str.data(), largo);
}

//eficiente, problemas de mantenimiento con bufsize
string readstring(fstream &fs, int largo)
{
	//char buffer[largo + 1];
	static char buffer[bufsize];
	buffer[largo] = '\0';
	fs.read(buffer, largo);
	return buffer;
}

//recomendada, menos eficiente, pero sin problemas de mantenibilidad
string readstring2(fstream &fs, int largo)
{
	char *buffer = new char[largo + 1];
	buffer[largo] = '\0';
	fs.read(buffer, largo);
	string str(buffer);
	delete[] buffer;
	return str;
}


#endif // RWSTRING_HPP_INCLUDED
