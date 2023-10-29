/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:42:27 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 21:58:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include<iostream>
#include<iomanip>
#include"../incl/AMateria.hpp"
#include"../incl/MateriaSource.hpp"
#include"../incl/Character.hpp"
#include"../incl/Ice.hpp"
#include"../incl/Cure.hpp"

#define FILL		40
#define C_DEFAULT	"\033[0m"
#define C_RED		"\033[1;91m"
#define C_GREEN		"\033[1;92m"
#define C_YELLOW	"\033[1;93m"
#define C_BLUE		"\033[1;94m"
#define C_PINK		"\033[1;95m"
#define C_CYAN		"\033[1;96m"
#define C_WHITE		"\033[1;97m"
#define C_PURPLE	"\033[1;38;2;150;25;250m"

// int main( void )
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

void    print_title( std::string msg, std::string clr_text, std::string clr_border )
{
	int	fill;
	int	odd;
	int	size;

	size = msg.length() >= FILL ? msg.length() + 10 : FILL;
	fill = ( size - msg.length() ) / 2;
	odd = msg.length() < FILL ? msg.length() % 2 : 0;
	std::cout << clr_border;
	std::cout << "\n " << std::setfill( '_' ) << std::setw( size ) << "" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( fill + odd ) << "" << clr_text << msg << clr_border << std::setw( fill + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( '_' ) << std::setw( size + 2 ) << "|\n" << std::endl;
	std::cout << C_DEFAULT;
}

int main( void )
{
	print_title( "1. Creating MateriaSource", C_GREEN, C_YELLOW );
	IMateriaSource* src = new MateriaSource();
	Floor *trash = new Floor();
	std::cout << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "2. \"src\" learning 5 materias", C_GREEN, C_YELLOW );
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	Ice	*mat = new Ice();
	src->learnMateria(mat);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	print_title( "3. Creating Character \"rynn\" and \"raeldor\"", C_GREEN, C_YELLOW );
	Character* rynn = new Character("rynn", trash);
	rynn->printMaterias();
	std::cout << std::endl;

	Character* raeldor = new Character("raeldor", trash);
	raeldor->printMaterias();
	std::cout << std::endl;

	trash->printFloor();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	print_title( "4. \"rynn\" trying to equip 5 materias and \"raeldor\" one materia", C_GREEN, C_YELLOW );
	rynn->equip(NULL);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	rynn->equip(tmp);
	tmp = src->createMateria("ice");
	rynn->equip(tmp);
	tmp = src->createMateria("cure");
	rynn->equip(tmp);
	tmp = src->createMateria("cure");
	rynn->equip(tmp);
	tmp = src->createMateria("ice");
	rynn->equip(tmp);

	std::cout << std::endl;
	rynn->printMaterias();

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	raeldor->equip(tmp);
	std::cout << std::endl;
	raeldor->printMaterias();
	std::cout << std::endl;

	trash->printFloor();

// ------------------------------------------------------------------------------------ //
	print_title( "5. Testing Character Assignation overload \"rynn = raeldor\" for deep copy and changed rynn afterwards", C_GREEN, C_YELLOW );
	*raeldor = *rynn;

	rynn->unequip(0);
	std::cout << "RYNN" << std::endl;
	rynn->printMaterias();
	std::cout << std::endl;

	std::cout << "RAELDOR" << std::endl;
	raeldor->printMaterias();

	trash->printFloor();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	print_title( "6. Testing character copy constructor for deep copy \"kthani = Character(rynn)\" and changed rynn afterwards", C_GREEN, C_YELLOW );

	rynn->printMaterias();
	
	Character* kthani = new Character(*rynn);
    kthani->printMaterias();

	tmp = src->createMateria("ice");
	rynn->equip(tmp);
	std::cout << "RYNN" << std::endl;
	rynn->printMaterias();
	std::cout << std::endl;

	std::cout << "KTHANI" << std::endl;
    kthani->printMaterias();

	trash->printFloor();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ 
	print_title( "7. \"rynn\" using all equiped materias on \"raeldor\" ", C_GREEN, C_YELLOW );
	rynn->use(0, *raeldor);
	rynn->use(1, *raeldor);
	rynn->use(2, *raeldor);
	rynn->use(3, *raeldor);
	rynn->use(10, *raeldor);
	rynn->use(-1, *raeldor);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "8. \"rynn\" trying to use unequiped materias on \"raeldor\" ", C_GREEN, C_YELLOW );
	rynn->unequip(0);
	rynn->use(0, *raeldor);

	trash->printFloor();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	print_title( "9. New character \"natsya\" equipping and unequipping materias", C_GREEN, C_YELLOW );
	ICharacter* natsya = new Character("natsya", trash);
	AMateria *cure = new Cure;
	AMateria *ice = new Ice;

	natsya->printMaterias();
	natsya->equip(cure);
	natsya->equip(ice);
	natsya->equip(cure);
	natsya->equip(ice);
	natsya->printMaterias();
	natsya->unequip(0);
	natsya->unequip(1);
	natsya->unequip(2);
	natsya->unequip(3);
	natsya->equip(cure);
	natsya->equip(ice);

	natsya->printMaterias();
	trash->printFloor();

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "10. Testing if unequiped materia is freed", C_GREEN, C_YELLOW );

	ICharacter* test = new Character("test", trash);

	tmp = src->createMateria("ice");
	test->equip(tmp);
   	test->unequip(0);

	trash->printFloor();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "11. Deleting \"floor\", \"rynn\", \"raeldor\", \"kthani\" and \"natsya\"", C_RED, C_YELLOW );

	print_title( "11 -> FLOOR", C_RED, C_YELLOW );
	trash->printFloor();
	delete trash;

	print_title( "11 -> TEST", C_RED, C_YELLOW );
	delete test;
	std::cout << std::endl;

	print_title( "11 -> NATSYA", C_RED, C_YELLOW );
	delete natsya;
	std::cout << std::endl;

	print_title( "11 -> KTHANI", C_RED, C_YELLOW );
	kthani->printMaterias();
	delete kthani;
	std::cout << std::endl;

	print_title( "11 -> RAELDOR", C_RED, C_YELLOW );
	raeldor->printMaterias();
	delete raeldor;
	std::cout << std::endl;

	print_title( "11 -> RYNN", C_RED, C_YELLOW );
	rynn->printMaterias();
	delete rynn;
	std::cout << std::endl;

	print_title( "11 -> SRC", C_RED, C_YELLOW );
	delete src;

	return (0);
}