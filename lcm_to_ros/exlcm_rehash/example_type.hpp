///////////////////////////////////////////////////////////////////////
// This message was automatically generated by ./rosmsg-gen.sh
// https://github.com/nrjl/lcm_to_ros, nicholas.lawrance@oregonstate.edu
///////////////////////////////////////////////////////////////////////
//
// Source message:    lcm/example_type.lcm
// Creation:          Thu 16 Jul 2020 12:36:37 PM EDT
//
///////////////////////////////////////////////////////////////////////
#ifndef __exlcm_rehash_example_type_hpp__
#define __exlcm_rehash_example_type_hpp__

#include "exlcm/example_type.hpp"

namespace exlcm_rehash
{

class example_type : public exlcm::example_type
{
    public:
        inline int encode(void *buf, int offset, int maxlen) const;
        inline int decode(const void *buf, int offset, int maxlen);
        inline static int64_t getHash();
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int example_type::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int example_type::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int64_t example_type::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

uint64_t example_type::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x0123456789abcdefLL;
    return hash;
}

}

#endif
