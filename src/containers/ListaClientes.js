import _ from "lodash";
import React, { Component } from "react";
import { connect } from "react-redux";
import { fetchClientes } from "../actions/clientes";
import { Link } from "react-router-dom";

class ListaClientes extends Component {
    componentWillMount() {
        this.props.fetchClientes();
    }

    renderClientes() {
        return _.map(this.props.clientes, clientes => {
            return (
                <tr key={clientes.id}>
                    <th scope="row">{clientes.nome}</th>
                    <td>{clientes.endereco}</td>
                    <td>{clientes.telefone}</td>
                    <td>{clientes.dataNasc}</td>
                    <td>
                        <Link to="/clientes/cadastro/{clientes.id}">
                            Editar
                        </Link>
                    </td>
                </tr>
            );
        });
    }
    render() {
        return (
            <div>
                <table className="table">
                    <thead className="thead-light">
                        <tr>
                            <th scope="col">Nome</th>
                            <th scope="col">Endereço</th>
                            <th scope="col">Telefone</th>
                            <th scope="col">Data de nascimento</th>
                            <th scope="col">Editar</th>
                        </tr>
                    </thead>
                    <tbody>{this.renderClientes()}</tbody>
                </table>
            </div>
        );
    }
}

function mapStateToProps(state) {
    return { clientes: state.clientes };
}

export default connect(
    mapStateToProps,
    { fetchClientes }
)(ListaClientes);
