#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glew.h>
#include <glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	/*!
	 * Construct shader program
	 *
	 * \param vertexPath : path till vertex shader
	 * \param fragmentPath : path till fragment shader
	 */
	Shader(const char* vertexPath, const char* fragmentPath);
	
	/*!
	 * Using the Shader program
	 *
	 */
	void use();

	// uniform setters
	//----------------

	/*!
	 * uniform to set 'bool'
	 * 
	 * \param name : name of variable in shader
	 * \param value : value to link with shader variable
	 */
	void setBool(const std::string &name, bool value) const;

	/*!
	 * uniform to set 'int'
	 * 
	 * \param name : name of variable in shader
	 * \param value : value to link with shader variable
	 */
	void setInt(const std::string &name, int value) const;

	/*!
	 * uniform to set 'float'
	 *
	 * \param name : name of variable in shader
	 * \param value : value to link with shader variable
	 */
	void setFloat(const std::string &name, float value) const;


	/*!
	 * uniform to set 'vec2'
	 * 
	 * \param name : name of variable in shader
	 * \param value : glm::vec2 to be link in shader variable
	 */
	void setVec2(const std::string &name, const glm::vec2 &value) const;

	/*!
	 * uniform to set 'vec2'
	 * 
	 * \param name : name of variable in shader
	 * \param x : x component of vector
	 * \param y : y component of vector
	 */
	void setVec2(const std::string &name, float x, float y) const;

	/*!
	 * uniform to set 'vec3'
	 * 
	 * \param name : name of variable in shader
	 * \param value : glm::vec3 to be link in shader variable
	 */
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	
	/*!
	 * uniform to set 'vec3'
	 *
	 * \param name : name of variable in shader
	 * \param x : x component of vector
	 * \param y : y component of vector
	 * \param z : z component of vector
	 */
	void setVec3(const std::string &name, float x, float y, float z) const;

	/*!
	 * uniform to set 'vec4'
	 *
	 * \param name : name of variable in shader
	 * \param value : glm::vec4 to be link in shader variable
	 */
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	
	/*!
	 * uniform to set 'vec4'
	 * 
	 * \param name : name of variable in shader
	 * \param x : x component of vector
	 * \param y : y component of vector
	 * \param z : z component of vector
	 * \param w : w component of vector
	 */
	void setVec4(const std::string &name, float x, float y, float z, float w) const;

	/*!
	 * uniform to set 'mat2'
	 * 
	 * \param name : name of variable in shader
	 * \param mat : glm::mat2 to be link in shader variable
	 */
	void setMat2(const std::string &name, const glm::mat2 &mat) const;

	/*!
	 * uniform to set 'mat3'
	 *
	 * \param name : name of variable in shader
	 * \param mat : glm::mat3 to be link in shader variable
	 */
	void setMat3(const std::string &name, const glm::mat3 &mat) const;


	/*!
	 * uniform to set 'mat4'
	 *
	 * \param name : name of variable in shader
	 * \param mat : glm::mat4 to be link in shader variable
	 */
	void setMat4(const std::string &name, const glm::mat4 &mat) const;
	
	//----------------

private:

	/*!
	 * Shader program unique id referring to location of it in GPU
	 * 
	 */
	unsigned int m_ShaderID;
	
	/*!
	* Shader Compilation
	*
	* \param source : shader source to compile
	* \param type : type of shader as defined in OpenGL
	* \return : shader id generated by compilation in OpenGL server
	*/
	unsigned int CompileShader(const std::string& source, unsigned int type);
	
	/*!
	 * Checking for compilation error
	 *
	 * \param component_id : as generated by OpenGL server
	 * \param type : type of component we want to check.
	 * should be pass in string like PROGRAM/VERTEX/FRAGMENT
	 * \return : true(bool) if compilation error else false(bool)
	 */
	bool IsCompileError(unsigned int component_id, const std::string& type);
};
#endif