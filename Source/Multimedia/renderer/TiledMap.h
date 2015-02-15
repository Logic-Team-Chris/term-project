#ifndef TILEDMAP_H
#define TILEDMAP_H

#include "BGO.h"

typedef char id_tile;

/**
 * Represents a tiled map.
 * Creates and draws them.
 * 
 * @author Melvin Loho
 */
class TiledMap : public BGO
{
public:
	struct Tile
	{
		id_tile id;
		sf::FloatRect rect;
	};

	/**
	 * Constructor.
	 */
	TiledMap();

	/**
	 * Destructor.
	 */
	~TiledMap();

	/**
	 * Sets the map texture.
	 *
	 * @param texture the texture
	 */
	void setTexture(const sf::Texture& texture);

	/**
	 * Creates a new tile.
	 *
	 * @param id the id of the tile
	 * @param x  the x position
	 * @param y  the y position
	 * @param w  the width
	 * @param h  the height
	 */
	void createTile(id_tile id, float x, float y, float w, float h);

	/**
	 * Adds a tile to the map.
	 *
	 * @param id the id of the tile
	 */
	void addTile(id_tile id);

	/**
	 * Draws the tiled map.
	 *
	 * @param batch  the batcher to be used for rendering
	 * @param states the render states to be used for rendering
	 */
	void draw(Batch &batch, sf::RenderStates states) const;

private:
	std::vector<Tile> m_tiles;
	sf::VertexArray m_vertices;

	sf::Texture *m_texture;
};

#endif // TILEDMAP_H