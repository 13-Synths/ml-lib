/*
 * ml-lib, a machine learning library for Max and Pure Data
 * Copyright (C) 2013 Carnegie Mellon University
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef ml_formatter__
#define ml_formatter__

#include <string>

namespace ml_doc
{
    class formattable_message_descriptor;
    class formattable_class_descriptor;

    class generic_formatter
    {
    public:
        virtual ~generic_formatter() {}
        virtual std::string format(const formattable_message_descriptor &descriptor) const = 0;
        virtual std::string format(const formattable_class_descriptor &descriptor) const = 0;
    };
    
    class max_formatter : public generic_formatter
    {
    public:
        virtual std::string format(const formattable_message_descriptor &descriptor) const;
        virtual std::string format(const formattable_class_descriptor &descriptor) const;
    };
    
    class max_help_formatter : public generic_formatter
    {
    public:
        virtual std::string format(const formattable_class_descriptor &descriptor) const;
        virtual std::string format(const formattable_message_descriptor &descriptor) const { return ""; }
        
    private:
        virtual std::string format(const formattable_message_descriptor &descriptor, const uint16_t message_y, const uint16_t obj_id) const;

    };
    
    class pd_help_formatter : public generic_formatter
    {
    public:
        virtual std::string format(const formattable_class_descriptor &descriptor) const;
        virtual std::string format(const formattable_message_descriptor &descriptor) const { return ""; }; // It's not meaningful to return "one line" of a Pd patch

    private:
        std::string format(const formattable_message_descriptor &f, const uint16_t message_x, const uint16_t message_y, uint16_t &objects_added) const;
    };
    
    class html_table_formatter : public generic_formatter
    {
    public:
        virtual std::string format(const formattable_message_descriptor &descriptor) const;
        virtual std::string format(const formattable_class_descriptor &descriptor) const;

    };
    
}



#endif /* defined(ml_formatter__) */
