//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//
// ============================================================
//
// Utils.hpp
//


//
// Declares a bunch of binder auxilary functions
//
// ============================================================

#ifndef __BINDER_UTILS_HPP__
#define __BINDER_UTILS_HPP__

#include "bindertypes.hpp"

extern LocaleID g_lcid;

namespace BINDER_SPACE
{
    inline BOOL EqualsCaseInsensitive(SString &a, SString &b)
    {
        return a.EqualsCaseInsensitive(b, g_lcid);
    }

    inline ULONG HashCaseInsensitive(SString &string)
    {
        return string.HashCaseInsensitive(g_lcid);
    }

    HRESULT FileOrDirectoryExists(PathString &path);
    HRESULT FileOrDirectoryExistsLog(PathString &path);

    BOOL IsURL(SString &urlOrPath);

    void MutateUrlToPath(SString &urlOrPath);
    void MutatePathToUrl(SString &pathOrUrl);

    // Mutates path
    void PlatformPath(SString &path);
    void CanonicalizePath(SString &path, BOOL fAppendPathSeparator = FALSE);

    // It is safe to use either A or B as CombinedPath.
    void CombinePath(SString &pathA,
                     SString &pathB,
                     SString &combinedPath);

    HRESULT GetTokenFromPublicKey(SBuffer &publicKeyBLOB,
                                  SBuffer &publicKeyTokenBLOB);

    BOOL IsFileNotFound(HRESULT hr);
};

#endif
