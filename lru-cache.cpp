/*

lru cache

Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key 
exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.


*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include "common.h"

using namespace std;

struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v) : key(k), value(v) { }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
    	// 查询或者访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
    	if(_cachemap.find(key) == _cachemap.end()) {
    		return -1;
    	} else {
    		_cachelist.splice( _cachelist.begin(), _cachelist, _cachemap[ key ] );
    		_cachemap[ key ] = _cachelist.begin();
    		return _cachemap[key]->value;
    	}
    }
    
    void set(int key, int value) {
        // 插入节点时，如果cache的size达到了上限，则删除尾部节点，同时要在hash表中删除对应的项。新节点都插入链表头部
        if(_cachemap.find(key) == _cachemap.end()) {
        	if(_cachelist.size() == _cap) {
        		_cachemap.erase( _cachelist.back().key );
        		_cachelist.pop_back();
        	}
        	_cachelist.push_front( CacheNode(key, value) );
        	_cachemap[ key ] = _cachelist.begin();
        } else {
        	_cachemap[ key ]->value =  value;
        	_cachelist.splice( _cachelist.begin(), _cachelist, _cachemap[key] );
        	_cachemap[ key ] = _cachelist.begin();
        }
    }
private:
	// 越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
	list<CacheNode> _cachelist;
	unordered_map<int, list<CacheNode>::iterator > _cachemap;
	int _cap;
};


int main(int argc, char* argv[]) {
	return 0;
}
