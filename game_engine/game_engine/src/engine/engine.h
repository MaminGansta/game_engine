#pragma once

#include <string>
#include <vector>
#include <algorithm>

// spdlog
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


// imgui
#include "imgui.h"
#include "imgui-SFML.h"


// sfml
#include "SFML/OpenGL.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>


// engine
#include "application/application.h"
#include "log/log.h"
#include "entry_point.h"
#include "layers/layer.h"
#include "layers/layer_array.h"

