// ---------------------------------------------------------------------
//
// Copyright (C) 2010 - 2018 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// make sure a TableHandler can be copied


#include <deal.II/base/data_out_base.h>
#include <deal.II/base/table_handler.h>

#include <string>
#include <vector>

#include "../tests.h"


int
main()
{
  initlog();

  /* Like in _06 */
  TableHandler table;
  table.set_auto_fill_mode(true);

  std::string keys[3] = {"key1", "key2", "key3"};

  // fill rows 1 and 2 partially
  table.add_value(keys[0], 0);
  table.add_value(keys[0], 1);
  // now fill row 3 completely
  table.add_value(keys[0], 2);
  table.add_value(keys[1], 13);
  table.add_value(keys[2], std::string("a"));

  // now again fill row 4 partially
  table.add_value(keys[0], 1);

  /* Now copy and write the file from the copy */
  TableHandler table2;
  table2 = table;

  // produce output. hope that row 4 is
  // completely padded
  table2.write_text(deallog.get_file_stream(),
                    TableHandler::table_with_separate_column_description);
}
