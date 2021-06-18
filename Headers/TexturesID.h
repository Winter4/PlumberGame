#pragma once

// идентификаторы текстур
namespace Textures {
	enum ID {
		Background,
		Field,
		Tales,
		TalesBase,
		Arrow
	};
}

// идентификаторы шрифтов
namespace Fonts {
	enum ID {
		Calibri
	};
}

// типы тайлов
	enum TaleType {
		NONE,
		Straight,
		Angle,
		T,
		X
	};

	// стороны трубы
	enum Side {
		Left,
		Top,
		Right,
		Bot
	};
