/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//******************************AIO MOD CLIENTS******************************//
//***************************************************************************//
//***************************************************************************//


/***********************************************************/
/********************* IS VALID CLIENT *********************/
/***********************************************************/
stock bool:IsClientValid(client) 
{ 
    return ((client > 0 && client <= MaxClients) && IsClientInGame(client)) ? true : false; 
} 