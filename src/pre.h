/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2012 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef PRE_H
#define PRE_H

class BufStr;

void initPreprocessor();
void cleanUpPreprocessor();
void addSearchDir(const char *dir);
void preprocessFile(const char *fileName,BufStr &input,BufStr &output);
void preFreeScanner();

#endif
