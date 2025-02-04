#include <string>
#include <utility>
#include <iostream>


//#include <boost/multi_index/member.hpp>
//#include <boost/multi_index/sequenced_index.hpp>
//#include <boost/multi_index/random_access_index.hpp>
//#include <boost/multi_index_container.hpp>
//#include <boost/multi_index/ordered_index.hpp>
//#include <boost/multi_index/hashed_index.hpp>
//#include <boost/multi_index/identity.hpp>
//#include <boost/multi_index/mem_fun.hpp>
//
//
//#include <boost/bimap.hpp>
//#include <boost/bimap/unconstrained_set_of.hpp>
//#include <boost/bimap/multiset_of.hpp>
//#include <boost/bimap/support/lambda.hpp>
//
//
//
//#include <boost/container/vector.hpp>
//#include <boost/container/stable_vector.hpp>


#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>




#include <boost/ptr_container/ptr_vector.hpp>


//using namespace boost::multi_index;
//using namespace boost::container;
//using namespace boost::intrusive;

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

//CHAPTER 12 - MULTI_INDEX_CONTAINER

//struct animal
//{
//    std::string name;
//    int legs;
//};

//HASHED NON UNIQUE
//typedef multi_index_container<
//    animal,
//    indexed_by<
//    hashed_non_unique<
//    member<animal, std::string, &animal::name>
//    >,
//    hashed_non_unique<
//    member<animal, int, &animal::legs>
//    >
//    >
//> animal_multi;


//HASHED UNIQUE
//typedef multi_index_container<
//    animal,
//    indexed_by<
//    hashed_non_unique<
//    member<animal, std::string, &animal::name>
//    >,
//    hashed_unique<
//    member<animal, int, &animal::legs>
//    >
//    >
//> animal_multi;

//typedef multi_index_container<
//    animal,
//    indexed_by<
//    sequenced<>,
//    ordered_non_unique<member<animal, int, &animal::legs> //Objects sorted automatically with this interface
//    >,
//    random_access<>
//    >
//> animal_multi;

//int main()
//{
//    animal_multi animals;
//
//    animals.insert({ "cat", 4 });
//    animals.insert({ "shark", 0 });
//    animals.insert({ "spider", 8 });
//    animals.insert({ "cat", 4 });
//    animals.insert({ "octopus", 8 });
//
//    std::cout << "Finding cat and displaying the number of it's legs" << std::endl;
//    auto it = animals.find("cat");
//    if (it != animals.end())
//    {
//        std::cout << it->legs << std::endl;
//    }
//
//    std::cout << "Number of cats" << std::endl;
//    std::cout << animals.count("cat") << std::endl;
//
//    std::cout << "Number of animals with 8 legs" << std::endl;
//
//    const animal_multi::nth_index<1>::type& legs_index = animals.get<1>();  
//    //OR - auto& leg_index = animals.get<1>();
//
//    std::cout << legs_index.count(8) << std::endl;
//
//
//    MODIFYING
//    animal_multi animals;
//
//    animals.insert({ "cat", 4 });
//    animals.insert({ "shark", 0 });
//    animals.insert({ "spider", 8 });
//    //animals.insert({ "cat", 4 });
//    //animals.insert({ "octopus", 8 });
//
//    auto& legs_index = animals.get<1>();
//    auto it = legs_index.find(4);
//    legs_index.modify(it, [](animal& a)
//        {
//            a.name = "dog";
//        });
//
//    std::cout << "Number of dogs after modification" << std::endl;
//    std::cout << animals.count("dog") << std::endl;
//    std::cout << "Number of cats after modification" << std::endl;
//    std::cout << animals.count("cat") << std::endl;
//
//    TESTING THE HASHED_UNIQUE FUNCTIONALITY
//    animal_multi animals;
//
//    //No two animals with the same number of legs will be added to the container, since the number of legs is used an a non-unique index
//    animals.insert({ "cat", 4 });
//    animals.insert({ "shark", 0 });
//    animals.insert({ "dog", 4 });
//
//    auto& legs_index = animals.get<1>();
//    std::cout << legs_index.count(4) << std::endl;
//
//    animal_multi animals;
//
//    animals.push_back({ "cat", 4 });
//    animals.push_back({ "shark", 0 });
//    animals.push_back({ "spider", 8 });
//
//    auto& legs_index = animals.get<1>();
//
//    //ACCESSING ANIMALS WITH LEGS BETWEEN 4 AND 8
//    auto it = legs_index.lower_bound(4);
//    auto end = legs_index.upper_bound(8);
//
//    for (; it != end; it++)
//    {
//        std::cout << it->name << std::endl;
//    }
//
//    //RANDOM ACCESS
//    const auto& rand_index = animals.get<2>();
//
//    std::cout << "Accessing all elements of the container >> " << std::endl;
//    std::cout << rand_index[0].name << std::endl;
//    std::cout << rand_index[1].name << std::endl;
//    std::cout << rand_index[2].name << std::endl;
//    
//}


//KEY EXTRACTORS - IDENTITY AND CONST_MEM_FUNCTION
//class animal
//{
//public:
//    animal(std::string name, int legs) : name_{ std::move(name) },
//        legs_(legs) {}
//    bool operator<(const animal& a) const { return legs_ < a.legs_; }
//    const std::string& name() const { return name_; }
//private:
//    std::string name_;
//    int legs_;
//};
//
//typedef multi_index_container<
//    animal,
//    indexed_by<
//    ordered_unique<
//    identity<animal>
//    >,
//    hashed_unique<
//    const_mem_fun<
//    animal, const std::string&, &animal::name
//    >
//    >
//    >
//> animal_multi;
//
//int main()
//{
//    animal_multi animals;
//
//    animals.emplace("cat", 4);
//    animals.emplace("shark", 0);
//    animals.emplace("spider", 8);
//
//    std::cout << animals.begin()->name() << '\n';
//
//    const auto& name_index = animals.get<1>();
//    std::cout << name_index.count("shark") << '\n';
//}


//KEY EXTRACTORS - GLOBAL_FUN AND COMPOSITE_KEY

//struct animal
//{
//	std::string name;
//	int legs;
//	bool has_tail;
//};
//
//class animal_container
//{
//public:
//
//	std::vector<animal> animals;
//	void add(animal a)
//	{
//		animals.push_back(a);
//
//		//TODO: Implement this member function
//		
//	}
//	const animal* find_by_name(const std::string& name) const
//	{
//		for (auto& ani : animals)
//		{
//			if (ani.name == name)
//			{
//				return &ani;
//			}
//		}
//
//		//TODO: Implement this member function
//		return nullptr;
//	}
//	std::vector<animal> find_by_legs(int from, int to) const
//	{
//		std::vector<animal> newVec;
//		for (auto ani : animals)
//		{
//			if (ani.legs >= from || ani.legs < to)
//			{
//				newVec.push_back(ani);
//			}
//		}
//		return newVec;
//
//		//TODO: Implement this member function
//		//return {};
//	}
//	std::vector<animal>find_by_tail(bool has_tail) const
//	{
//		std::vector<animal> newVec;
//		for (auto ani : animals)
//		{
//			if (ani.has_tail = has_tail)
//			{
//				newVec.push_back(ani);
//			}
//		}
//		return newVec;
//
//		//TODO: Implement this member function
//		//return {};
//
//	}
//};
//
//int main()
//{
//	animal_container animals;
//	animals.add({ "cat", 4, true });
//	animals.add({ "ant", 6, false });
//	animals.add({ "spider", 8, false });
//	animals.add({ "shark", 0, false });
//
//	const animal* a = animals.find_by_name("cat");
//	if (a)
//	{
//		std::cout << "Cat has " << a->legs << " legs" << std::endl;
//	}
//
//	auto animals_with_6_to_8_legs = animals.find_by_legs(6, 9);
//	for (auto a : animals_with_6_to_8_legs)
//	{
//		std::cout << a.name << " has " << a.legs << " legs" << std::endl;
//	}
//
//
//	auto animals_without_tail = animals.find_by_tail(false);
//	for (auto a : animals_without_tail)
//	{
//		std::cout << a.name << " has no tail" << std::endl;
//	}
//}


//CHAPTER 13 - BIMAP

//INTRO
//int main()
//{
//	typedef boost::bimap<std::string, int> bimap;
//	bimap animals;
//
//	animals.insert({ "cat", 4 });
//	animals.insert({ "shark", 0 });
//	animals.insert({ "spider", 8 });
//
//	std::cout << animals.left.count("cat") << std::endl;
//	std::cout << animals.right.count(8) << std::endl;
//
//}

//ACCESSING RELATIONS

//int main()
//{
//	typedef boost::bimap<std::string, int> bimap;
//	bimap animals;
//
//	animals.insert({ "cat", 4 });
//	animals.insert({ "shark", 0 });
//	animals.insert({ "spider", 8 });
//
//	for (auto it = animals.begin(); it != animals.end(); it++)
//	{
//		std::cout << it->left << " has " << it->right << " legs" << std::endl;
//	}
//}

//boost::bimaps::set_of explicitly

//int main()
//{
//	typedef boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>> bimap;
//	bimap animals;
//
//	animals.insert({ "cat", 4 });
//	animals.insert({ "shark", 0 });
//	animals.insert({ "spider", 8 });
//
//	std::cout << animals.left.count("spider") << std::endl;
//	std::cout << animals.right.count(8) << std::endl;
//}

//boost::bimaps::multiset_of
//Keys don't need to be unique
//int main()
//{
//	typedef boost::bimap<boost::bimaps::set_of<std::string>, boost::bimaps::multiset_of<int>> bimaps;
//	bimaps animals;
//
//	animals.insert({ "cat", 4 });
//	animals.insert({ "shark", 0 });
//	animals.insert({ "dog", 4 });
//
//	std::cout << animals.left.count("dog") << std::endl;
//	std::cout << animals.right.count(4) << std::endl;
//}

//Disabling one side of the bimap
//boost::bimaps::unconstrained_set_of
//int main()
//{
//	typedef boost::bimap<std::string, boost::bimaps::unconstrained_set_of<int>> bimap;
//	bimap animals;
//
//	animals.insert({ "cat", 4 });
//	animals.insert({ "shark", 0 });
//	animals.insert({ "spider", 8 });
//
//	auto it = animals.left.find("cat");
//	animals.left.modify_key(it, boost::bimaps::_key = "dog");
//
//	std::cout << it->first << std::endl;
//}


//Chapter 20 - BOOST.CONTAINER


//Recursive containers with Boost.Container

//struct animal
//{
//	vector<animal> children;
//};
//
//int main()
//{
//	animal parent, child1, child2;
//	parent.children.push_back(child1);
//	parent.children.push_back(child2);
//}


//boost::container::stable_vector

//int main()
//{
//	stable_vector<int> v(2, 1);
//
//	int& i = v[1];
//	v.erase(v.begin());
//	std::cout << i << std::endl;
//}

//Other containers provided by Boost::Container

//CHECK
//boost::container::flat_set
//boost::container::flat_map
//boost::container::slist
//boost::container::static_vector

//struct animal
//{
//	std::string name;
//	vector<animal> children;
//};
//
//
////stable_vector - doesn't invalidate iterators and references
//stable_vector<animal> animals;
//
//
////flat_set - think sorted vector
//flat_set<animal> animals2;



//Boost.Intrusive
//Containers which don't store copies of objects but original objects

//Lifetime of elements must be managed by user
//Types must be setup to be used in containers
//Lots of containers provided

//Intrusive containers don�t allocate memory dynamically.
//A call to push_back() doesn�t lead to a dynamic allocation with new.
//This is a one reason why intrusive containers can improve performance.


//struct animal : public list_base_hook<>
//{
//	std::string name;
//	animal(const std::string &n)
//		:name(n)
//	{
//
//	}
//};
//
//int main()
//{
//	typedef list<animal> animal_list;
//
//	animal_list animals;
//	animal lion("lion");
//	animals.push_back(lion);
//}


//struct animal : public list_base_hook<>
//{
//	std::string name;
//	int legs;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//};
//
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal a3{ "spider", 8 };
//
//	typedef list<animal> animal_list;
//	animal_list animals;
//
//	animals.push_back(a1);
//	animals.push_back(a2);
//	animals.push_back(a3);
//
//	a1.name = "dog";
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}


//struct animal : public list_base_hook<>
//{
//	std::string name;
//	int legs;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//};
//
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal a3{ "spider", 8 };
//
//	typedef list<animal> animal_list;
//	animal_list animals;
//
//	animals.push_back(a1);
//	animals.push_back(a2);
//	animals.push_back(a3);
//
//	a1.name = "dog";
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}

//Removing and destroying dynamically allocated objects

//struct animal : public list_base_hook<>
//{
//	std::string name;
//	int legs;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//};
//
////Because intrusive containers don�t store copies, you must remove objects from intrusive containers before you destroy them.
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal *a3 = new animal{ "spider", 8 };
//
//	typedef list<animal> animal_list;
//	animal_list animals;
//
//	animals.push_back(a1);
//	animals.push_back(a2);
//	animals.push_back(*a3);
//
//	animals.pop_back();
//	delete a3;
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}

//Removing and destroying with pop_back_and_dispose()

//struct animal : public list_base_hook<>
//{
//	std::string name;
//	int legs;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//};
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal *a3 = new animal{ "spider", 8 };
//
//	typedef list<animal> animal_list;
//	animal_list animals;
//
//	animals.push_back(a1);
//	animals.push_back(a2);
//	animals.push_back(*a3);
//
//	animals.pop_back_and_dispose([](animal* a)
//		{
//			delete a;
//		});
//	//The other elements in the list haven�t been created with new and, thus, must not be destroyed with delete.
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}



//Removing and destroying with auto unlink mode


//The auto unlink mode automatically removes an element from an intrusive container when it is destroyed

//The auto unlink mode can only be used if the member function size(), which is provided by all intrusive containers, 
//has no constant complexity. By default, it has constant complexity, which means: 
//the time it takes for size() to return the number of elements doesn�t depend on how many elements are stored in a container. 
//Switching constant complexity on or off is another option to optimize performance.

//typedef link_mode<auto_unlink> mode;
//
//
//struct animal : public list_base_hook<mode>
//{
//	std::string name;
//	int legs;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//};
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal* a3 = new animal{ "spider", 8 };
//
//	typedef constant_time_size<false> constant_time_size;
//	typedef list<animal, constant_time_size> animal_list;
//
//	animal_list animals;
//
//	animals.push_back(a1);
//	animals.push_back(a2);
//	animals.push_back(*a3);
//
//	delete a3;
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}




//Defining a hook for boost::intrusive::set as a member variable

//struct animal
//{
//	std::string name;
//	int legs;
//	set_member_hook<> set_hook;
//	animal(std::string n, int l)
//		:name{ std::move(n) }, legs{ l }
//	{
//
//	}
//	bool operator<(const animal& a) const
//	{
//		return legs < a.legs;
//	}
//};
//
//
//int main()
//{
//	animal a1{ "cat", 4 };
//	animal a2{ "shark", 0 };
//	animal a3{ "spider", 8 };
//
//	typedef member_hook<animal, set_member_hook<>, &animal::set_hook> hook;
//	typedef set<animal, hook> animal_set;
//	animal_set animals;
//
//	animals.insert(a1);
//	animals.insert(a2);
//	animals.insert(a3);
//
//	for (const animal& a : animals)
//	{
//		std::cout << a.name << std::endl;
//	}
//}


//CHAPTER 2 - BOOST.POINTERCONTAINER

//Using boost::ptr_vector

int main()
{
	boost::ptr_vector<int> v;
	v.push_back(new int{ 1 });
	v.push_back(new int{ 2 });
	std::cout << v.back() << std::endl;
}