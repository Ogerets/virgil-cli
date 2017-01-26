/**
 * Copyright (C) 2015-2016 Virgil Security Inc.
 *
 * Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3) Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VIRGIL_CLI_ARGUMENT_VALUE_H
#define VIRGIL_CLI_ARGUMENT_VALUE_H

#include <string>

namespace cli { namespace argument {

class ArgumentValue {
public:
    ArgumentValue();

    explicit ArgumentValue(bool value);

    explicit ArgumentValue(size_t value);

    explicit ArgumentValue(std::string value);

    std::string origin() const;

    // Primitive

    bool isEmpty() const;

    bool isBool() const;

    bool isNumber() const;

    bool isString() const;

    bool asBool() const;

    bool asOptionalBool() const;

    size_t asNumber() const;

    std::string asString() const;

    // Complex

    bool isKeyValue() const;

    bool isKeyValueAlias() const;

    std::string key() const;

    std::string value() const;

    std::string alias() const;
private:
    enum class Kind {
        Empty = 0,
        Boolean = 1,
        Number = 2,
        String = 4,
        KeyValue = 8,
        KeyValueAlias = 16
    };
    void throwIfNotKind(Kind kind) const;
    static const char* kindAsString(Kind kind);
private:
    Kind kind_ = Kind::Empty;
    std::string origin_;
    std::string key_;
    std::string value_;
    std::string alias_;
};

}}

namespace std {

string to_string(const cli::argument::ArgumentValue& argumentValue);

}

#endif //VIRGIL_CLI_ARGUMENT_VALUE_H
