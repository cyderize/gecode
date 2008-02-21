/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Guido Tack <tack@gecode.org>
 *
 *  Copyright:
 *     Guido Tack, 2008
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "test/branch.hh"

#ifdef GECODE_HAS_CPLTSET_VARS

namespace Test { namespace Branch {

  /// Test branching
  class CpltSet : public CpltSetTest {
  public:
    /// Create and register test
    CpltSet(const std::string& s, const Gecode::IntSet& d, int n)
      : CpltSetTest(s,n,d) {}
    /// Post propagators on variables \a x
    virtual void post(Gecode::Space* home, Gecode::CpltSetVarArray& x) {
      Gecode::CpltSetVarArgs xx(x.size()-1);
      for (int i=x.size()-1; i--;)
        xx[i] = x[i];
      Gecode::partition(home, xx, x[x.size()-1]);
    }
  };

  namespace {
    Gecode::IntSet d_dense(-2,3);
    const int v_sparse[5] = {-10,-5,0,5,10};
    Gecode::IntSet d_sparse(v_sparse,5);

    CpltSet d_3("Dense::3",d_dense,3);
  }

}}

#endif

// STATISTICS: test-branch
