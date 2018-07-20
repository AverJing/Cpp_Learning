/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

//ex10.10
//Why do you think the algorithms don¡¯t change the size of containers ?

/*The aim of this design is to separate the algorithms 
	and the operation provided by member function.
	Cause the library algorithms operate on iterators, not containers. 
	Thus, an algorithm cannot (directly) add or remove elements
*/