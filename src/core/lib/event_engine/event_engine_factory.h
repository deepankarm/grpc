// Copyright 2021 The gRPC Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef GRPC_CORE_LIB_EVENT_ENGINE_EVENT_ENGINE_FACTORY_H
#define GRPC_CORE_LIB_EVENT_ENGINE_EVENT_ENGINE_FACTORY_H

#include <grpc/support/port_platform.h>

#include <memory>

#include <grpc/event_engine/event_engine.h>

namespace grpc_event_engine {
namespace experimental {

/// Access the shared global EventEngine instance.
///
/// The concept of a global EventEngine may go away in a post-iomgr world.
/// Strongly consider whether you could use \a CreateEventEngine instead.
EventEngine* GetDefaultEventEngine();

/// Create an EventEngine using the default factory provided at link time.
std::unique_ptr<EventEngine> DefaultEventEngineFactory();

/// Reset the default event engine
void ResetDefaultEventEngine();

// TODO(hork): remove this when any other EE usage is landed
void InitializeEventEngine();

}  // namespace experimental
}  // namespace grpc_event_engine

#endif  // GRPC_CORE_LIB_EVENT_ENGINE_EVENT_ENGINE_FACTORY_H
