/**********************************************************************************/
/* MIT License                                                                    */
/*                                                                                */
/* Copyright (c) 2021 JetBrains-Research                                          */
/*                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/**********************************************************************************/

#ifndef SPBLA_OPENCL_BACKEND_HPP
#define SPBLA_OPENCL_BACKEND_HPP

#include <memory>

#include <backend/backend_base.hpp>
#include <core/controls.hpp>

namespace spbla {

    class OpenCLBackend: public BackendBase {
    private:
        static std::pair<int, int> getVersion();
        static int getWarp();
    public:
        ~OpenCLBackend() override = default;

        void initialize(hints initHints) override;

        void finalize() override;

        bool isInitialized() const override;

        MatrixBase *createMatrix(size_t nrows, size_t ncols) override;

        void releaseMatrix(MatrixBase *matrixBase) override;

        void queryCapabilities(spbla_DeviceCaps &caps) override;

        void queryAvailableDevices();

        static std::shared_ptr<clbool::Controls> controls;

        static const int NVIDIA_WARP = 32;
        static const int AMD_WARP = 64;
    };


}

#endif //SPBLA_OPENCL_BACKEND_HPP