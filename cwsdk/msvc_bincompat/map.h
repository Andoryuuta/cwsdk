#pragma once
#include <cstdint>
#include <map>

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
namespace MSVCBinCompat {
	// MSVC red-black binary search tree node
	struct RBBST_node
	{
		RBBST_node *left;
		RBBST_node *parent;
		RBBST_node *right;
		char color;
		char isnil;
		__int16 _pad;
	};

	template <typename KT, typename VT>
	struct MyMap_node
	{
		RBBST_node rbbst;
		KT key;
		VT val;
	};

	template <typename KT, typename VT>
	struct map {
		typedef MyMap_node<KT, VT> node_t;
	private:
		node_t head;
		void inorder(node_t* node, std::map<KT, VT>* output)
		{
			if (!node->rbbst.isnil) {
				inorder((node_t*)node->rbbst.left, output);
				output->insert_or_assign(node->key, node->val);
				inorder((node_t*)node->rbbst.right, output);
			}
		}
	public:
		std::map<KT, VT> CopyToSTDMap() {
			auto out = std::map<KT, VT>();
			inorder((node_t*)head.rbbst.parent, &out);
			return out;
		}
		// Search
		// Insert
		// Delete
	};
};