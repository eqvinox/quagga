/*
 * Interface looking up by netlink.
 * Copyright (C) 1998 Kunihiro Ishiguro
 *
 * This file is part of GNU Zebra.
 *
 * GNU Zebra is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Zebra is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Zebra; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.  
 */

#include <zebra.h>

#include "zebra/zserv.h"
#include "ioctl.h"

extern int interface_lookup_netlink (void);

/* Interface information read by netlink. */
void
interface_list (void)
{
  interface_lookup_netlink ();  
}

int if_set_vlan(struct interface *ifp, int id)
{
	return kernel_vlan_set (ifp, id);
}




/* set interface MTU */
void
if_set_mtu (struct interface *ifp, unsigned int mtu)
{
	mtu = kernel_set_link_mtu(ifp, mtu);
}


/* Set interface flags */
int
if_set_flags (struct interface *ifp, uint64_t flags)
{
  int ret;
  struct ifreq ifreq;

  return kernel_link_set_flags(ifp,flags);

}
/* Unset interface's flag. */
int
if_unset_flags (struct interface *ifp, uint64_t flags)
{

	 return kernel_link_unset_flags(ifp, flags);
}

/* Unset interface's flag. */
int
if_delete_if (struct interface *ifp)
{

	 return kernel_delete_if(ifp);
}

#if NETLINK_STATS
int
if_update_stats (struct interface *ifp)
{
	return kernel_update_link_stats(ifp);
}
#endif
