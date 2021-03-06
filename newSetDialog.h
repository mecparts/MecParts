/*
 * newSetDialog.h
 * 
 * Copyright 2012 Wayne Hortensius <whortens@shaw.ca>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef _NEWSETSDIALOG_H
#define _NEWSETSDIALOG_H

#include <boost/regex.hpp>
#include "mecparts.h"

using namespace std;

class NewSetDialog
{
	public:
		NewSetDialog(Glib::RefPtr<Gtk::Builder> pRefBuilder);
		virtual ~NewSetDialog();
		
		string SetNumber() { return m_pNewSetNumber->get_text(); };
		string Description() { return m_pNewSetDescription->get_text(); };
		int Started();
		int Ended();
		gint Run(string errorLabel);
		void Hide();
		
	private:
		Gtk::Dialog *m_pDialog;
	
		bool on_delete_event(GdkEventAny *e);
		void on_setInfo_changed_event();
		Gtk::Label *m_pNewSetErrorLabel;
		Gtk::Entry *m_pNewSetNumber;
		Gtk::Entry *m_pNewSetDescription;
		Gtk::Entry *m_pNewSetStarted;
		Gtk::Entry *m_pNewSetEnded;
		Gtk::Button *m_pNewSetOkButton;
		boost::regex m_whitespaceRegex;
};

#endif // _NEWSETDIALOG_H
