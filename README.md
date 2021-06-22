# MyZork
## Author
I'm Miquel Miro and this is MyZork version of the original game Zork.
## Commands
Possible directions, you can use the full name or only the first letter:
* north ( n )
* west ( w )
* south ( s )
* east ( e )

Commands, as the directions you can use the full name or only the first letter:
* ( h ) help -> to get information on all possible commands
* ( q ) quit -> to exit the game
* ( l ) look -> to look the room
* ( l ) look direction -> to look at a direction of the room
* ( m ) move direction -> to move from a room to another
* ( e ) examine -> to examine the room for entities
* ( e ) examine entity -> to examine a item or a creature of the room or inventory (ex.: e Orc)
* ( i ) inventory -> to see the items of your inventory
* ( p ) pick item -> to pick an item of a room (ex.: p Sword)
* ( d ) drop item -> to drop an item to a room
* ( s ) stats -> to see the stats of your hero
* ( eq ) equip item -> to equip an item of the inventory
* ( a ) attack creature -> to attack a creature of a room
* ( c ) combine item1 item2 -> to combine items of the inventory (you only can combine equipables with upgrades)

## Guide
The game consists in 5 rooms in the following disposition (X are empty):

X F X

D E T

O X X


* E - Entrance: you can find a Sword to equip
* F - Forge: you can find a MagicRune to upgrade the Sword (IronKey needed)
* D - DarkRoom: you can find a IronKey
* O - OrcRoom: you can find a GoldenKey protected by an Orc
* T - TreasureChamber: you have to arrive here to win (GoldenKey needed)

To win you need to arrive to the TreasureChamber, and for that you need the GoldenKey protected by the orc. The orc is pretty strong so to win him you need to equip an upgraded sword, you will find the Sword at the entrance and you can upgraded combining it with the MagicRune found in the Forge and for entering the Forge you need the IronKey found in the DarkRoom.

## Links

[Github](https://github.com/miquelmiro3/MyZork)

## License

MIT License

Copyright (c) 2021 - Miquel Miro Rovira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.