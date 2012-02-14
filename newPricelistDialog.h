/*
 * newPricelistDialog.h
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

#ifndef _NEWPRICELISTDIALOG_H
#define _NEWPRICELISTDIALOG_H

#include "mecparts.h"
#include "pricelistsStore.h"

using namespace std;

class NewPricelistDialog
{
	public:
		NewPricelistDialog(Glib::RefPtr<Gtk::Builder> pRefBuilder);
		virtual ~NewPricelistDialog();
		
		Gtk::Dialog *m_pDialog;
	
		void ErrorLabel(string text) { m_pNewPricelistErrorLabel->set_text(text); }
		string Description() { return m_pNewPricelistDescription->get_text(); };
		string CurrencyCode();
		void ClearInput();
		
	private:
		bool on_delete_event(GdkEventAny *e);
		void on_input_changed_event();
		Gtk::Label *m_pNewPricelistErrorLabel;
		Gtk::Entry *m_pNewPricelistDescription;
		Gtk::ComboBox *m_pNewPricelistCurrencyComboBox;
		Gtk::Button *m_pNewPricelistOkButton;
		PricelistsStore m_pricelistsStore;

};

#endif // _NEWPRICELISTDIALOG_H
