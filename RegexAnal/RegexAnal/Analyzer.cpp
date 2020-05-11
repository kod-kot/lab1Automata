#include "Analyzer.h"



Analyzer::Analyzer(std::string __name, std::string __input_file_path, std::string __output_file_path, std::string __conflicts_types_file_path) :
	_name(__name),
	_input_file_path(__input_file_path),
	_output_file_path(__output_file_path),
	_conflicts_types_file_path(__conflicts_types_file_path)
{}

Analyzer::~Analyzer()
{}

void Analyzer::open_files()
{
	_input_file.open(_input_file_path);
	if (!_input_file.is_open()) {
		throw std::invalid_argument((_name + ": Input file is not open (ERROR)").c_str());
	}
	std::cout << _name << ": Input file opened" << std::endl;

	_output_file.open(_output_file_path, std::ios_base::trunc);
	if (!_output_file.is_open()) {
		throw std::invalid_argument((_name + ": Output file is not open (ERROR)").c_str());
	}
	std::cout << _name << ": Output file opened" << std::endl;

	_conflicts_types_file.open(_conflicts_types_file_path, std::ios_base::trunc);
	if (!_output_file.is_open()) {
		throw std::invalid_argument((_name + ": Conflicts types output file is not open (ERROR)").c_str());
	}
	std::cout << _name << ": Conflicts types output file opened" << std::endl;
}

void Analyzer::close_files()
{
	if (_input_file.is_open()) {
		_input_file.close();
		std::cout << _name << ": Input file closed" << std::endl;
	}
	if (_output_file.is_open()) {
		_output_file.close();
		std::cout << _name << ": Output file closed" << std::endl;
	}
	if (_conflicts_types_file.is_open()) {
		_conflicts_types_file.close();
		std::cout << _name << ": Conflicts types output file closed" << std::endl;
	}
}