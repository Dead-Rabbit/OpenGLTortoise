//
// Created by 王子潇 on 2021/2/24.
//

#include "MineUtils.h"

using namespace std;

MineUtils::MineUtils() {}

string MineUtils::readShaderSource(string filePath) {
    string content;
    ifstream fileStream(filePath, ios::in);
    if (fileStream.fail()){
        cout << "Error opening file " << filePath << endl;
        exit(1);
    }

    string line = "";
    while(!fileStream.eof()){
        getline(fileStream, line);
        content.append(line + "\n");
    }
    fileStream.close();
    return content;
}

GLuint MineUtils::createShaderProgram(const char * vertShaderPath, const char * fragShaderPath) {
    string fillVertShaderPath = string("../shader/").append(vertShaderPath);
    string fillFragShaderPath = string("../shader/").append(fragShaderPath);
    string vShaderStr = readShaderSource(fillVertShaderPath);
    string fShaderStr = readShaderSource(fillFragShaderPath);

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint vfprogram = glCreateProgram();

	const char * vertShaderSrc = vShaderStr.c_str();
	const char * fragShaderSrc = fShaderStr.c_str();

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	glAttachShader(vfprogram, vShader);
	glAttachShader(vfprogram, fShader);
	glLinkProgram(vfprogram);

	return vfprogram;
}
