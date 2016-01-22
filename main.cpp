/**
 * @file        test.cpp
 * @autor    	zhou xiangxiang <xiangxiangzhou@aliyun.com>
 * @version 	1.0
 * @section	LICNESE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 * 
 */
#include <cassert>
#include <cstdlib>
#include <iostream> 
#include <algorithm>
#include <list>

#define MESSAGE_NUM 	5
#define INPUT_DATA_NUM 	100

/** 
 * generate randoms, store them into a list as the input data.
 */
const std::list<unsigned> input_data() {
	std::list<unsigned> data;
	for (int i = 0; i < INPUT_DATA_NUM; ++i) {
		data.push_back(random());
	}
	return data;
}


/**
 * if 'data' is larger than the minimum parameter in the 'buffer';
 * 	then insert it into 'buffer', and delete the least parameter.
 * else
 *	return.
 */
void insert_res(std::list<unsigned>& buffer, unsigned data) {
	std::list<unsigned>::iterator i = buffer.begin();
	for (i; i != buffer.end(); ++i) {
		if (data < *i) 
			break;
	}
	if (i != buffer.begin()) {  
		buffer.insert(i, data); // attention
		buffer.pop_front();
	}
}

/**
 * @param   data    : input data.
 *
 * @return  buffer  : output data(result).
 */
const std::list<unsigned> get_res(const std::list<unsigned>& data) {
	// 'buffer' used to store result, must be initialized.
	std::list<unsigned> buffer(MESSAGE_NUM, 0);  
	assert(buffer.size() == MESSAGE_NUM);
	std::for_each(buffer.begin(), buffer.end(), [](unsigned i) {  assert(i == 0); });
	
	// data
	for (std::list<unsigned>::const_iterator i = data.begin(); i !=  data.end(); ++i) {
		insert_res(buffer, *i);
	}

	return buffer;
}

int main(int argc, char **argv) {
	std::list<unsigned> data = input_data();
	if (data.empty())
		return 0;

	const std::list<unsigned> res  = get_res(data);

	data.sort();
	auto r_it = res.end();
	auto d_it = data.end();
	while (r_it != res.begin())	
		assert(*(--r_it) == *(--d_it));

	assert(0);
	return 0;	
}
