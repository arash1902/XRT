/**
 * Copyright (C) 2019-2020 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// ------ I N C L U D E   F I L E S -------------------------------------------
// Local - Include Files
#include "SubCmdDump.h"
#include "tools/common/XBUtilities.h"
namespace XBU = XBUtilities;

// 3rd Party Library - Include Files
#include <boost/program_options.hpp>
namespace po = boost::program_options;

// System - Include Files
#include <iostream>

// ----- C L A S S   M E T H O D S -------------------------------------------

SubCmdDump::SubCmdDump(bool _isHidden, bool _isDepricated, bool _isPreliminary)
    : SubCmd("dump", 
             "See replacement functionality in command: 'examine'")
{
  const std::string longDescription = "Dumps the internal JSON database representation of the various internal 'queries'";
  setLongDescription(longDescription);
  setExampleSyntax("");
  setIsHidden(_isHidden);
  setIsDeprecated(_isDepricated);
  setIsPreliminary(_isPreliminary);
}

void
SubCmdDump::execute(const SubCmdOptions& _options) const
// Reference Command:  dump

{
  XBU::verbose("SubCommand: dump");
  // -- Retrieve and parse the subcommand options -----------------------------
  bool help = false;

  po::options_description dumpDesc("dump options");
  dumpDesc.add_options()
    ("help", boost::program_options::bool_switch(&help), "Help to use this sub-command")
  ;


  // Parse sub-command ...
  po::variables_map vm;

  try {
    po::store(po::command_line_parser(_options).options(dumpDesc).run(), vm);
    po::notify(vm); // Can throw
  } catch (po::error& e) {
    std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
    printHelp(dumpDesc);

    // Re-throw exception
    throw;
  }

  // Check to see if help was requested or no command was found
  if (help == true)  {
    printHelp(dumpDesc);
    return;
  }

  // -- Now process the subcommand --------------------------------------------

  XBU::error("COMMAND BODY NOT IMPLEMENTED.");
  // TODO: Put working code here
}

