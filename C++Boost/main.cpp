
//BOOST libraries

//15 Container libraries in Boost (ordered by importance)

//Boost.Multiindex
//Boost.Bimap
//Boost.Container
//Boost.Intrusive
//Boost.PointerContainer
//Boost.CircularBuffer
//Boost.Lockfree
//Boost.PropertyTree
//Boost.DynamicBitset 
//Boost.Multiarray
//Boost.Heap
//Boost.Array
//Boost.Unordered

//Boost.ICL
//Boost.PropertyMap



//SIDE NOTE
//Boost.Tuple
//Boost.Fusion
//Boost.Graph
//Boost.Signals 


//class Animal
//{
//public:
//	Animal(const std::string& n, bool d, int l)
//		:name(n), dangerous_(d), legs_(l) {}
//	
//	std::string name;
//	
//	bool dangerous() const { return dangerous_; }
//	
//	int legs() { return legs_; }
//
//private:
//	bool dangerous_;
//	int legs_;
//};
//
//typedef multi_index_container <
//	Animal, //element to put in container
//	indexed_by<
//	hashed_unique<  //interface and how it should lookup elements in container
//	member<Animal, std::string, &Animal::name>>, //Lookup by its name
//	hashed_non_unique< //interface
//	const_mem_fun<Animal, bool, &Animal::dangerous>> //Lookup if the animals are dangerous or not
//	>
//	> animals_type;
//
//animals_type;
//
//
//int main()
//{
//	//Define multiindex container
//	
//
//	animals_type animals;
//
//	animals.insert(Animal("lion", true, 4));
//	animals.insert(Animal("cat", false, 4));
//	animals.insert(Animal("shark", true, 0));
//
//	auto it = animals.find("lion");
//
//	if (it != animals.end())
//	{
//		cout << it->dangerous() << endl;
//	}
//	cout << animals.count("lion") << endl;
//}


//struct person
//{
//	std::string name;
//	int age;
//};
//
//typedef multi_index_container<                        // multi_index_container definition
//	person,
//	indexed_by<
//	hashed_non_unique<
//	member<
//	person, std::string, &person::name
//	>
//	>,
//	hashed_non_unique<
//	member<
//	person, int, &person::age
//	>
//	>
//	>
//> person_multi;
//
//int main() {
//	person_multi people;
//
//	people.insert({ "Rajiv", 23 });                         // Inserting 
//	people.insert({ "Navneet", 21 });                       // Into
//	people.insert({ "Pramod", 28 });                        // multi_index
//
//	std::cout << people.count("Navneet") << '\n';
//
//	const person_multi::nth_index<1>::type& age = people.get<1>();
//	std::cout << age.count(28) << '\n';
//}

int main()
{

}