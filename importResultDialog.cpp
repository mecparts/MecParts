/*
 * importResultDialog.cpp: display the results of importing a csv file
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

#include <iostream>
#include <sstream>
#include <vector>
#include "importResultDialog.h"

using namespace std;

ImportResultDialog::ImportResultDialog(Glib::RefPtr<Gtk::Builder> pRefBuilder) :
	m_pDialog(NULL),
	m_pPartsAddedLabel(NULL),
	m_pPartsUpdatedLabel(NULL),
	m_pUnknownPartsTextView(NULL),
	m_pImportResultDialogOkButton(NULL)
{
	GET_WIDGET(pRefBuilder,"importResultDialog",m_pDialog)
	m_pDialog->signal_delete_event().connect(sigc::mem_fun(*this,&ImportResultDialog::on_delete_event));

	GET_WIDGET(pRefBuilder,"partsAddedLabel",m_pPartsAddedLabel)
	GET_WIDGET(pRefBuilder,"partsUpdatedLabel",m_pPartsUpdatedLabel)
	GET_WIDGET(pRefBuilder,"unknownPartsTextView",m_pUnknownPartsTextView)
	GET_WIDGET(pRefBuilder,"importResultDialogOkButton",m_pImportResultDialogOkButton)
}

ImportResultDialog::~ImportResultDialog()
{
	delete m_pDialog;
}

bool ImportResultDialog::on_delete_event(GdkEventAny *e)
{
	return false;
}

gint ImportResultDialog::Run(int numAdded,int numUpdated,vector<string> unknownParts)
{
	stringstream temp;
	temp << numAdded;
	m_pPartsAddedLabel->set_text(temp.str());
	temp.str("");
	temp << numUpdated;
	m_pPartsUpdatedLabel->set_text(temp.str());
	temp.str("");
	for( unsigned i=0; i<unknownParts.size(); ++i ) {
		temp << unknownParts[i] << endl;
	}
	m_pUnknownPartsTextView->get_buffer()->set_text(temp.str());
	return m_pDialog->run();
}

void ImportResultDialog::Hide()
{
	m_pDialog->hide();
}
